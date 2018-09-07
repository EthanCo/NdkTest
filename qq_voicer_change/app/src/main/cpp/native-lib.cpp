#include <jni.h>
#include <string>
#include "common.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_ethanco_qq_1voicer_1change_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_ethanco_qq_1voicer_1change_MainActivity_getButtonLabel(JNIEnv *env, jobject instance,
                                                                jint index) {

    return env->NewStringUTF(Common_BtnStr((Common_Button)index));
}extern "C"
JNIEXPORT void JNICALL
Java_com_ethanco_qq_1voicer_1change_MainActivity_buttonDown(JNIEnv *env, jobject instance,
                                                            jint index) {
    //gDownButtons |= (1 << index);
}extern "C"
JNIEXPORT void JNICALL
Java_com_ethanco_qq_1voicer_1change_MainActivity_buttonUp(JNIEnv *env, jobject instance,
                                                          jint index) {

    // TODO

}extern "C"
JNIEXPORT void JNICALL
Java_com_ethanco_qq_1voicer_1change_MainActivity_setStateCreate(JNIEnv *env, jobject instance) {

    // TODO

}extern "C"
JNIEXPORT void JNICALL
Java_com_ethanco_qq_1voicer_1change_MainActivity_setStateStart(JNIEnv *env, jobject instance) {

    // TODO

}extern "C"
JNIEXPORT void JNICALL
Java_com_ethanco_qq_1voicer_1change_MainActivity_setStateStop(JNIEnv *env, jobject instance) {

    // TODO

}extern "C"
JNIEXPORT void JNICALL
Java_com_ethanco_qq_1voicer_1change_MainActivity_setStateDestroy(JNIEnv *env, jobject instance) {

    // TODO

}extern "C"
JNIEXPORT void JNICALL
Java_com_ethanco_qq_1voicer_1change_MainActivity_main(JNIEnv *env, jobject instance) {

    // TODO

}

/*extern "C"
{

jstring Java_org_fmod_example_MainActivity_getButtonLabel(JNIEnv *env, jobject thiz, jint index)
{
    return env->NewStringUTF(Common_BtnStr((Common_Button)index));
}

void Java_org_fmod_example_MainActivity_buttonDown(JNIEnv *env, jobject thiz, jint index)
{
    gDownButtons |= (1 << index);
}

void Java_org_fmod_example_MainActivity_buttonUp(JNIEnv *env, jobject thiz, jint index)
{
    gDownButtons &= ~(1 << index);
}

void Java_org_fmod_example_MainActivity_setStateCreate(JNIEnv *env, jobject thiz)
{

}

void Java_org_fmod_example_MainActivity_setStateStart(JNIEnv *env, jobject thiz)
{
	gSuspendState = false;
}

void Java_org_fmod_example_MainActivity_setStateStop(JNIEnv *env, jobject thiz)
{
	gSuspendState = true;
}

void Java_org_fmod_example_MainActivity_setStateDestroy(JNIEnv *env, jobject thiz)
{
	gQuitState = true;
}

void Java_org_fmod_example_MainActivity_main(JNIEnv *env, jobject thiz)
{
	gJNIEnv = env;
	gMainActivityObject = thiz;

	FMOD_Main();
}

}*/