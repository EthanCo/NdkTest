#include <jni.h>
#include <stdlib.h>

#include <android/log.h>

#define LOGI(FORMAT,...) __android_log_print(ANDROID_LOG_INFO,"jason",FORMAT,__VA_ARGS__)
#define LOGE(FORMAT,...) __android_log_print(ANDROID_LOG_ERROR,"jason",FORMAT,__VA_ARGS__)

//JNIEXPORT jstring JNICALL
//Java_com_heiko_ndkfilepatchtest_MainActivity_stringFromJNI(JNIEnv *env, jclass jclass) {
//    return (*env)->NewStringUTF(env, "Hello NDK From C");
//}
//
//JNIEXPORT jint JNICALL
//Java_com_heiko_ndkfilepatchtest_MainActivity_calcValue(JNIEnv *env, jobject instance, jint a,
//                                                       jint b) {
//    return a + b;
//}

long get_file_size(char *path){
    FILE *fp = fopen(path,"rb");
    fseek(fp,0,SEEK_END);
    return ftell(fp);
}

JNIEXPORT void JNICALL
Java_com_heiko_ndkfilepatchtest_NDKFileUtils_diff(JNIEnv *env, jobject jo, jstring path_jstr,
                                                  jstring path_pattern_jstr,
                                                  jint file_num) {
    //把Java的jString 转为 char*
    const char *path = (*env)->GetStringUTFChars(env, path_jstr, NULL); //需要分割的文件路径
    const char *path_pattern = (*env)->GetStringUTFChars(env, path_pattern_jstr, NULL);


    LOGI("Z-diff-path:%s",path);
    LOGI("Z-diff-path_pattern:%s",path_pattern);
    //得到分割之后子文件的路径列表
    char **patches = malloc(sizeof(char *) * file_num);
    for (int i = 0; i < file_num; ++i) {
        patches[i] = malloc(sizeof(char *) * 100); //这里偷懒了
        //元素赋值
        //需要分隔的文件:C://jason/liuyan.png
        //子文件：C://jason/liuyan_%d.png
        sprintf(patches[i], path_pattern, (i + 1));
        LOGI("Z-diff-patch path:%s",patches[i]);
    }

    //不断读取path文件，循环写入file_num个文件中
    //整除
    //文件大小:90，查房9个文件，每个文件10
    //不整除
    //文件大小:110，分成9个文件
    //前(9-1)个文件为(110/(9-1))=13
    //最后一个文件 (110%(9-1)) = 6
    int i = 0;
    int filesize = get_file_size(path);
    FILE *fpr = fopen(path,"rb");
    //整除
    if(filesize % file_num == 0){
        //单个文件大小
        int part = filesize / file_num;
        i = 0;
        //逐一写入不同的分割子文件中
        for (; i < file_num; i++) {
            FILE *fpw = fopen(patches[i], "wb");
            int j = 0;
            for(; j < part; j++){
                //边读边写
                fputc(fgetc(fpr),fpw);
            }
            fclose(fpw);
        }
    }else{
        //不整除
        int part = filesize / (file_num - 1);
        i = 0;
        //逐一写入不同的分割子文件中
        for (; i < file_num - 1; i++) {
            FILE *fpw = fopen(patches[i], "wb");
            int j = 0;
            for(; j < part; j++){
                //边读边写
                fputc(fgetc(fpr),fpw);
            }
            fclose(fpw);
        }
        //the last one
        FILE *fpw = fopen(patches[file_num - 1], "wb");
        i = 0;
        for(; i < filesize % (file_num - 1); i++){
            fputc(fgetc(fpr),fpw);
        }
        fclose(fpw);
    }

    //关闭被分割的文件
    fclose(fpr);

    //释放
    i = 0;
    for(; i < file_num; i++){
        free(patches[i]);
    }
    free(patches);

    //释放的操作
    (*env)->ReleaseStringUTFChars(env, path_jstr, path);
    (*env)->ReleaseStringUTFChars(env,path_pattern_jstr,path_pattern);
}

JNIEXPORT void JNICALL
Java_com_heiko_ndkfilepatchtest_NDKFileUtils_patch(JNIEnv *env, jclass jcls,jstring path_pattern_jstr,jstring merge_path_jstr, jint file_num) {
    /*const char *path = (*env)->GetStringUTFChars(env, path_, 0);
    (*env)->ReleaseStringUTFChars(env, path_, path);*/

    //合并之后的文件路径
    const char *merge_path = (*env)->GetStringUTFChars(env,merge_path_jstr,NULL);

    //分割子文件
    const char *path_pattern = (*env)->GetStringUTFChars(env,path_pattern_jstr,NULL);

    LOGI("Z-patch-merge_path:%s",merge_path);
    LOGI("Z-patch-path_pattern:%s",path_pattern);

    //得到分割之后的子文件的路径列表
    char **patches = malloc(sizeof(char*) * file_num);
    for (int i = 0; i < file_num; ++i) {
        //元素赋值
        //需要分割的文件：C://jason/liuyan.png
        //子文件：C://jason/liuyan_%d.png
        sprintf(patches[i],path_pattern,(i+1));
        LOGI("Z-patch path:%s",patches[i]);
    }

    FILE *fpw = fopen(merge_path,"wb");
    for (int i = 0; i < file_num; ++i) {
        //每个子文件的大小
        int filesize = get_file_size(patches[i]);
        FILE *fpr = fopen(patches[i],"rb");
        for (int j = 0; j < filesize; ++j) {
            fputc(fgetc(fpr),fpw);
        }
        fclose(fpr);
    }

    //释放
    for (int i = 0; i < file_num; ++i) {
        free(patches[i]);
    }
    free(patches);

    (*env)->ReleaseStringUTFChars(env,path_pattern_jstr,path_pattern);
    (*env)->ReleaseStringUTFChars(env,merge_path_jstr,merge_path);
}

JNIEXPORT jstring JNICALL
Java_com_heiko_ndkfilepatchtest_NDKFileUtils_stringFromJNI(JNIEnv *env, jobject jo) {
    LOGI("Z-Hello NDKFileUtils","");
    return (*env)->NewStringUTF(env, "Hello NDKFileUtils");
}