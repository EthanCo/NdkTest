#include <stdio.h>
#include <stdlib.h>

//JNIEnv�ṹ���ָ�����
typedef const struct JNINativeInterface_ *JNIEnv;

//�ṹ��
struct JNINativeInterface_{
	char* (*NewStringUTF)(JNIEnv*, char*);
};

//����ʵ��
char* NewStringUTF(JNIEnv* env, char* str){
	return str;
}

void main(){
	//ʵ�����ṹ��
	struct JNINativeInterface_ struct_env;
	struct_env.NewStringUTF = NewStringUTF;

	//�ṹ��ָ��
	JNIEnv e = &struct_env;

	//�ṹ��Ķ���ָ��
	JNIEnv *env = &e;

	//ͨ������ָ����ú���
	char* str = (*env)->NewStringUTF(env, "abc");
}