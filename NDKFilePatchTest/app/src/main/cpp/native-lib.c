#include <jni.h>
#include <stdlib.h>

JNIEXPORT jstring JNICALL
Java_com_heiko_ndkfilepatchtest_MainActivity_stringFromJNI(JNIEnv *env, jclass jclass) {
    return (*env)->NewStringUTF(env, "Hello NDK From C");
}

JNIEXPORT jint JNICALL
Java_com_heiko_ndkfilepatchtest_MainActivity_calcValue(JNIEnv *env, jobject instance, jint a,
                                                       jint b) {
    return a+b;
}

JNIEXPORT void JNICALL
Java_com_heiko_ndkfilepatchtest_NDKFileUtils_diff(JNIEnv *env, jclass type, jstring path_,
                                                  jint file_num) {
    //把Java的jString 转为 char*
    const char *path = (*env)->GetStringUTFChars(env, path_, 0); //需要分割的文件路径

    //得到分割之后子文件的路径列表
    char **patches = malloc(sizeof(char *) * file_num);
    for (int i = 0; i < file_num; ++i) {
        patches[i] = malloc(sizeof(char *) * 100);
        //元素赋值

    }

    //不断读取path文件，循环写入file_num个文件中

    //释放的操作
    (*env)->ReleaseStringUTFChars(env, path_, path);
}

JNIEXPORT void JNICALL
Java_com_heiko_ndkfilepatchtest_NDKFileUtils_patch(JNIEnv *env, jclass type, jstring path_,
                                                   jint file_num) {
    const char *path = (*env)->GetStringUTFChars(env, path_, 0);
    (*env)->ReleaseStringUTFChars(env, path_, path);
}