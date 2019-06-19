#include <jni.h>
#include <string>
#include <unistd.h>

extern "C" {
//封装格式
#include "libavformat/avformat.h"
//解码
#include "libavcodec/avcodec.h"
//缩放
#include "libswscale/swscale.h"
//重采样
#include "libswresample/swresample.h"
#include <libavutil/imgutils.h>
#include <android/native_window_jni.h>
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_heiko_mywangyiplayer_Player_stringFromJNI(JNIEnv *env, jobject instance) {
    char info[10000] = {0};
    sprintf(info, "%s\n", avcodec_configuration());
    return env->NewStringUTF(info);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_heiko_mywangyiplayer_Player_native_1start(JNIEnv *env, jobject instance, jstring path_,
                                                   jobject surface) {
    ANativeWindow *nativeWindow = ANativeWindow_fromSurface(env, surface);
    const char *path = env->GetStringUTFChars(path_, 0);
    //FFmpeg 视频绘制 音频绘制
    //初始化网络模块
    avformat_network_init();
    //声明上下文 (总上下文)
    AVFormatContext *formatContext = avformat_alloc_context();

    AVDictionary *opts = NULL;
    av_dict_set(&opts, "timeout", "3000000", 0); //3秒内打不开，就默认打开失败
    int ret = avformat_open_input(&formatContext, path, NULL, &opts);
    if (ret) {
        return;
    }
    //视频流
    //寻找流
    int vidio_stream_inx = -1;
    avformat_find_stream_info(formatContext, NULL);
    for (int i = 0; i < formatContext->nb_streams; ++i) {
        if (formatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
            vidio_stream_inx = i;
            break;
        }
    }

    //获取视频流
    AVStream *video_stream = formatContext->streams[vidio_stream_inx];
    //获取视频流参数
    AVCodecParameters *codecpar = video_stream->codecpar;
    //根据编解码上下文中的编码id查找对应的解码器
    AVCodec *dec = avcodec_find_decoder(codecpar->codec_id);
    //2.0 对应 avcodec_alloc_context1
    //4.0 对应 avcodec_alloc_context3
    AVCodecContext *codecContext = avcodec_alloc_context3(dec);
    //将解码器参数 copy到解码器上下文
    avcodec_parameters_to_context(codecContext, codecpar);
    //初始化AVCodeccontext以使用AVCodec
    avcodec_open2(codecContext, dec, NULL);
    //解码 YUV数据
    //AVPacket
    AVPacket *packet = av_packet_alloc();

    /**
     * 重视速度:fast_bilinear,point
     * 重视质量:cubic,spline,lanczos
     * 缩小:
     * 重视速度:fast_bilinear,point
     * 重视质量:gauss,bilinear
     * 重视锐度:cubic,spline,lanczos
     */
    SwsContext *sws = sws_getContext(codecContext->width, codecContext->height,
                                     codecContext->pix_fmt,
                                     codecContext->width, codecContext->height, AV_PIX_FMT_RGBA,
                                     SWS_BILINEAR, 0, 0,
                                     0);
    //更改窗口缓冲区的格式和大小。
    ANativeWindow_setBuffersGeometry(nativeWindow, codecContext->width, codecContext->height,
                                     WINDOW_FORMAT_RGBA_8888);
    ANativeWindow_Buffer outBuffer;
    while (av_read_frame(formatContext, packet) >= 0) {
        //将原始数据包数据作为输入提供给解码器
        avcodec_send_packet(codecContext, packet);
        //分配一个AVFrame并将其字段设置为默认值。产生的ruct必须使用av帧free来释放
        AVFrame *frame = av_frame_alloc();
        //从解码器返回解码后的输出数据。
        ret = avcodec_receive_frame(codecContext, frame);
        if (ret == AVERROR(EAGAIN)) {
            continue;
        } else if (ret < 0) {
            break;
        }
        //接收的容器
        uint8_t *dst_data[4];
        //每一行的首地址
        int dst_linesize[0];
        //分配大小为w和h的图像，像素格式为pix fmt，并相应地填充指针和行。必须使用av_ freep (&pointer [a])释放分配的映像缓冲区。
        av_image_alloc(dst_data, dst_linesize, codecContext->width, codecContext->height,
                       AV_PIX_FMT_RGBA, 1);
        //绘制
        sws_scale(sws, frame->data, frame->linesize, 0, frame->height, dst_data, dst_linesize);

        ANativeWindow_lock(nativeWindow, &outBuffer, NULL);

        //渲染
        uint8_t *firstWindown = static_cast<uint8_t *>(outBuffer.bits);
        //输入源(rgb)的
        uint8_t *src_data = dst_data[0];
        //拿到一行有多少个字节RGBA
        int destStride = outBuffer.stride * 4;
        int src_linesize = dst_linesize[0];
        for (int i = 0; i < outBuffer.height; ++i) {
            //内存拷贝 来进行渲染
            memcpy(firstWindown + i * destStride, src_data + i * src_linesize, destStride);
        }

        ANativeWindow_unlockAndPost(nativeWindow);
        usleep(1000 * 16);
        av_frame_free(&frame);

        env->FindClass("com.heiko.mywangyiplayer.Player");

    }


    env->ReleaseStringUTFChars(path_, path);
}