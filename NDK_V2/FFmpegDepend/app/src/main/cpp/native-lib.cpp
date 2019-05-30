#include <jni.h>
#include <string>

extern  "C" {
    #include "libavcodec/avcodec.h"
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_heiko_mywangyiplayer_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    char info[10000] = { 0 };
    sprintf(info, "%s\n", avcodec_configuration());
    return env->NewStringUTF(info);
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_heiko_mywangyiplayer_MainActivity_ffmpegInfo(JNIEnv *env, jobject instance) {
    char info[10000] = { 0 };
    sprintf(info, "%s\n", avcodec_configuration());
    return env->NewStringUTF(info);
}