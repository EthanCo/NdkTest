#include <jni.h>
#include <string>
#include "server.c"
#include "base.h"
#include "tserver.c"
#include "udp_server.c"

extern "C" JNIEXPORT jstring

JNICALL
Java_com_heiko_youmingudpservertest_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT void JNICALL
Java_com_heiko_youmingudpservertest_MainActivity_startUdpServer(JNIEnv *env, jobject instance) {
    LOGI("udp recv start");
    //main_recv();
    //my_recv();
    //t_recv();
    main_udp_recv("127.0.0.1",12669);
}