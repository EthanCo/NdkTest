#include <stdio.h>
#include <stdlib.h>

//JNIEnv结构体的指针别名
typedef const struct JNINativeInterface_ *JNIEnv;

//结构体
struct JNINativeInterface_{
	char* (*NewStringUTF)(JNIEnv*, char*);
};

//函数实现
char* NewStringUTF(JNIEnv* env, char* str){
	return str;
}

void main(){
	//实例化结构体
	struct JNINativeInterface_ struct_env;
	struct_env.NewStringUTF = NewStringUTF;

	//结构体指针
	JNIEnv e = &struct_env;

	//结构体的二级指针
	JNIEnv *env = &e;

	//通过二级指针调用函数
	char* str = (*env)->NewStringUTF(env, "abc");
}