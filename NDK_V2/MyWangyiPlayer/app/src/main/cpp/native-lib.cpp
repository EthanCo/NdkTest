#include <jni.h>
#include <string>

extern "C" {
#include "libavcodec/avcodec.h"
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
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
    const char *path = env->GetStringUTFChars(path_, 0);
    //FFmpeg 视频绘制 音频绘制
    //初始化网络模块
    avformat_network_init();
    //声明上下文 (总上下文)
    AVFormatContext *formatContext = avformat_alloc_context();

    AVDictionary * opts = NULL;
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

    //视频流参数
    AVCodecParameters *codecpar = formatContext->streams[vidio_stream_inx]->codecpar;
    //解码器 h264
    AVCodec *dec = avcodec_find_decoder(codecpar->codec_id);
    //2.0 对应 avcodec_alloc_context1
    //4.0 对应 avcodec_alloc_context3
    AVCodecContext *codecContext = avcodec_alloc_context3(dec);
    //将解码器参数 copy到解码器上下文
    avcodec_parameters_to_context(codecContext, codecpar);
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
    SwsContext * sws = sws_getContext(codecContext->width, codecContext->height, codecContext->pix_fmt,
                   codecContext->width, codecContext->height, AV_PIX_FMT_RGBA, SWS_BILINEAR, 0, 0,
                   0);
    while (av_read_frame(formatContext, packet) >= 0) {
        avcodec_send_packet(codecContext, packet);
        AVFrame *frame = av_frame_alloc();
        ret = avcodec_receive_frame(codecContext, frame);
        if (ret == AVERROR(EAGAIN)) {
            continue;
        }
    }


    env->ReleaseStringUTFChars(path_, path);
}