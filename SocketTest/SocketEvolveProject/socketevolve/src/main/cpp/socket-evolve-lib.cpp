#include <jni.h>
#include <string>
#include "base.h"
#include "udp_client.c"

void myInvokejavaTest(JNIEnv *env, jobject instance, const char *message) {
    //Android NDK开发(五)——C代码回调Java代码
    //https://blog.csdn.net/allen315410/article/details/41862479
    LOGI("start");

    //在C语言中调用Java的空方法
    //1.找到java代码native方法所在的字节码文件
    //jclass (*FindClass)(JNIEnv*, const char*);
    jclass clazz = env->FindClass("com/heiko/socketevolve/SocketEvolve");
    if (clazz == 0) {
        LOGD("find class error");
        return;
    }
    LOGD("find class");
    //2.找到class里面对应的方法
    // jmethodID (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    jmethodID method1 = env->GetMethodID(clazz, "notifyCallBack", "(Ljava/lang/String;)V"); //()V
    if (method1 == 0) {
        LOGD("find method1 error");
        return;
    }
    LOGD("find method1");
    //3.调用方法
    //void (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
    env->CallVoidMethod(instance, method1, env->NewStringUTF(message));
    LOGD("method1 called");
}

void string_recv_listener(const char *data, JNIEnv *env, jobject instance) {
    LOGI("string_recv_listener2>>%s", data);
    myInvokejavaTest(env, instance, data);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_heiko_socketevolve_SocketEvolve_sendUdp(JNIEnv *env, jobject instance, jstring message_,
                                                 jstring hostName_, jint port) {
    const char *message = env->GetStringUTFChars(message_, 0);
    const char *hostName = env->GetStringUTFChars(hostName_, 0);

    LOGI("message:%s hostName%s port:%d", message, hostName, port);
    udp_send(message, hostName, port, string_recv_listener, env, instance);

    env->ReleaseStringUTFChars(message_, message);
    env->ReleaseStringUTFChars(hostName_, hostName);
}