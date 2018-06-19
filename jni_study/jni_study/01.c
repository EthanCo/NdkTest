#define _CRT_SECURE_NO_WARNINGS
#include "com_ethanco_jni_JniTest.h"
#include <string.h>
#include <stdio.h> 
#include <stdlib.h> 

//函数实现
JNIEXPORT jstring JNICALL Java_com_ethanco_jni_JniTest_getStringFromC
(JNIEnv *env, jclass jcls){
	//简单的实现
	//将C的字符串转为一个java字符串
	return (*env)->NewStringUTF(env, "C String");
}

JNIEXPORT jstring JNICALL Java_com_ethanco_jni_JniTest_getStringFromC2
(JNIEnv *env, jobject jcls){
	return (*env)->NewStringUTF(env,"C String 2");
}

//每个native函数，都至少有两个参数(JNIEnv*,jclass或者jobject)
//当native方法(Java方法)代表静态方法时:       jclass 代表native方法(Java方法)所属类的class对象 (JniTest.class)
//当native方法(Java方法)代表非静态方法时:     jobject 代表native方法(Java方法)所属类的class对象 (JniTest.class)


//基本数据
//Java基本数据类型与JNI数据类型的映射关系
//Java类型->JNI类型->C类型
/*
boolean jboolean
byte jbyte;
char jchar;
short jshort;
int jint;
long jlong;
float jfloat;
double jdouble;
void void
*/

//引用类型(对象)
//String jstring
//object jobject
//数组,基本数据类型的数组
//byte[] jByteArray
//对象数组
//object[](String[]) jobjectArray

//C/C++访问java
//修改Java的属性并返回
JNIEXPORT jstring JNICALL Java_com_ethanco_jni_JniTest_accessField
(JNIEnv *env, jobject jobj){
	//得到jclass   jobj是t对象，JniTest.class
	jclass cls = (*env)->GetObjectClass(env, jobj);
	//得到属性名称      属性签名 ---->> (详见Java属性与方法签名列表.png)
	jfieldID fid = (*env)->GetFieldID(env, cls, "key", "Ljava/lang/String;");
	//获得key变量的值
	jstring jstr = (*env)->GetObjectField(env, jobj, fid);
	//printf("jstr:%#x\n", &jstr); //打印日志 Eclipse也能显示，但有延迟，比Java的慢
	//jason 改成 super jason   
	////参数三: jboolean指针类型 函数内会赋值这个传参，复制了isCopy为JNI_TRUE，没复制为JNI_FALSE，可直接传NULL
	char *c_str = (*env)->GetStringUTFChars(env, jstr, NULL); //先得到C的字符串 (这样才能修改)
	char text[20] = "super ";
	strcat(text, c_str); //拼接得到新的字符串

	jstring new_jstr = (*env)->NewStringUTF(env, text);

	//修改key
	(*env)->SetObjectField(env, jobj, fid, new_jstr);
	//printf("new_jstr:%#x\n", &new_jstr);
	return new_jstr;
}

//访问静态变量
JNIEXPORT void JNICALL Java_com_ethanco_jni_JniTest_accessStaticField
(JNIEnv * env, jobject jobj){
	//获取jclass
	jclass cls = (*env)->GetObjectClass(env, jobj);
	jfieldID fid = (*env)->GetStaticFieldID(env, cls, "count", "I");
	//GetStatic<Type>Field
	jint count = (*env)->GetStaticIntField(env, cls, fid);
	count++;
	//修改
	//setSatatic<Type>Filed
	 (*env)->SetStaticIntField(env, cls, fid, count);
}

//访问Java方法 (最常用)
JNIEXPORT void JNICALL Java_com_ethanco_jni_JniTest_accessMethod
(JNIEnv * env, jobject jobj){
	jclass cls = (*env)->GetObjectClass(env, jobj);
	//签名获取方式 java项目bin目录下  javap -s -p 包名.类名 ， 会列出该类所有方法的签名，比如getRandomInt的是(I)I
	//获取jmethodID 方法ID
	jmethodID mid = (*env)->GetMethodID(env, cls, "getRandomInt", "(I)I");
	//调用 Call<Type>Method
	jint random = (*env)->CallIntMethod(env, jobj, mid, 200); //jint是long 类型，取的别名
	printf("random num:%ld", random);
}

//访问Java静态方法
JNIEXPORT void JNICALL Java_com_ethanco_jni_JniTest_accessStaticMethod
(JNIEnv * env, jobject jobj){
	//jclass
	jclass cls = (*env)->GetObjectClass(env, jobj);
	//jmethodID
	jmethodID mid = (*env)->GetStaticMethodID(env, cls, "getUUID", "()Ljava/lang/String;"); //; 分号别忘了!!!!!
	//调用
	//CallSatatic<Type>Method
	jstring uuid = (*env)->CallStaticObjectMethod(env, cls, mid);

	//随机文件名称
	//jstring -> char*
	////参数三: jboolean指针类型 函数内会赋值这个传参，复制了isCopy为JNI_TRUE，没复制为JNI_FALSE，可直接传NULL
	char *uuid_str = (*env)->GetStringUTFChars(env, uuid, NULL);
	//拼接
	char fileName[100];
	sprintf(fileName, "D://%s.txt", uuid_str); 
	FILE *fp = fopen(fileName, "w");
	fputs("i love jason", fp);
	fclose(fp);
}

//访问构造方法
//使用java.util.Date产生一个当前的时间戳
JNIEXPORT jobject JNICALL Java_com_ethanco_jni_JniTest_accessConstructor
(JNIEnv *env, jobject jobj){
	jclass cls = (*env)->FindClass(env, "java/util/Date");
	//jmethodID， "<init>" 构造方法
	jmethodID constructor_mid = (*env)->GetMethodID(env, cls, "<init>", "()V");
	//实例化一个Date对象
	jobject date_obj = (*env)->NewObject(env, cls, constructor_mid);
	//调用getTime方法
	jmethodID mid = (*env)->GetMethodID(env, cls, "getTime", "()J");
	jlong time = (*env)->CallLongMethod(env, date_obj, mid);

	printf("\ntime:%lld\n", time);
	return date_obj;
}

//调用父类的方法
//获取java中 public Human man = new Man(); 中的Human这个父类
JNIEXPORT void JNICALL Java_com_ethanco_jni_JniTest_accessNonvirtualMethod
(JNIEnv *env, jobject jobj){
	/*jclass cls = (*env)->GetObjectClass(env, jobj);
	//获取man对象
	jfieldID fid = (*env)->GetFieldID(env, cls, "human", "Lcom/ethanco/jni/bean/Human;");
	//获取
	jobject human_obj = (*env)->GetStaticObjectField(env, jobj, fid);

	//执行sayHi方法
	jclass human_cls = (*env)->FindClass(env, "com/ethanco/jni/bean/Human");
	jmethodID mid = (*env)->GetMethodID(env, human_cls, "sayHi", "()V");

	//执行
	//(*env)->CallObjectMethod(env, human_obj, mid); //还是用子类的方法
	(*env)->CallNonvirtualObjectMethod(env, human_obj, human_cls, mid); //调用父类的方法*/

	jclass cls = (*env)->GetObjectClass(env, jobj);
	//获取man属性（对象）
	jfieldID fid = (*env)->GetFieldID(env, cls, "man001", "Lcom/ethanco/jni/bean/Human;");
	//获取
	jobject human_obj = (*env)->GetObjectField(env, jobj, fid);

	//执行sayHi方法
	jclass human_cls = (*env)->FindClass(env, "com/ethanco/jni/bean/Human"); //注意：传父类的名称
	jmethodID mid = (*env)->GetMethodID(env, human_cls, "sayHi", "()V");

	//执行
	//(*env)->CallObjectMethod(env, human_obj, mid);
	//调用的父类的方法
	(*env)->CallNonvirtualObjectMethod(env, human_obj, human_cls, mid);
}

//把java的string转化成c的字符串
char*   myJstring2CStr(JNIEnv*   env, jstring   jstr)
{
	char*   rtn = NULL;
	jclass   clsstring = (*env)->FindClass(env, "java/lang/String");  //String
	jstring   strencode = (*env)->NewStringUTF(env, "GB2312"); //"gb2312"
	jmethodID   mid = (*env)->GetMethodID(env, clsstring, "getBytes", "(Ljava/lang/String;)[B"); //getBytes(Str);
	jbyteArray   barr = (jbyteArray)(*env)->CallObjectMethod(env, jstr, mid, strencode); // String .getByte("GB2312");
	jsize   alen = (*env)->GetArrayLength(env, barr);
	jbyte*   ba = (*env)->GetByteArrayElements(env, barr, JNI_FALSE);
	if (alen   >   0)
	{
		rtn = (char*)malloc(alen + 1);         //"\0"
		memcpy(rtn, ba, alen);
		rtn[alen] = 0;
	}
	(*env)->ReleaseByteArrayElements(env, barr, ba, 0);  //释放内存空间
	return rtn;
}

//中文问题
JNIEXPORT jstring JNICALL Java_com_ethanco_jni_JniTest_chineseChars
(JNIEnv *env, jobject jobj, jstring in){
	//输出
	//char *c_str = (*env)->GetStringUTFChars(env, in, NULL);
	//printf("%s\n", c_str);

	//jstring jstr = (*env)->NewStringUTF(env, c_str); 用C直接转用的是UTF-8，而java传的中文是GB2312，会乱码
	
	
	//思路是用Java的方法来执行
	//执行String(byte bytes[],String charsetName) 构造方法需要的条件
	//1.jmethodID
	//2.byte数组
	//3.字符编码jstring
	//char *c_str = "马蓉与宋江";
	char *c_str = myJstring2CStr(env, in); //把java的string转化成c的字符串
	printf("%s\n", c_str);

	jclass str_cls = (*env)->FindClass(env, "java/lang/String");
	jmethodID constructor_mid = (*env)->GetMethodID(env, str_cls, "<init>", "([BLjava/lang/String;)V");

	//jbyte -> char 
	//jbyteArray -> char[]
	jbyteArray bytes = (*env)->NewByteArray(env, strlen(c_str));
	//byte数组赋值
	//0->strlen(c_str)，从头到尾
	//对等于，从c_str这个字符数组，复制到bytes这个字符数组
	(*env)->SetByteArrayRegion(env, bytes, 0, strlen(c_str), c_str);

	//字符编码jstring
	jstring charsetName = (*env)->NewStringUTF(env, "GB2312");

	//调用构造函数，返回编码之后的jstring
	return (*env)->NewObject(env, str_cls, constructor_mid, bytes, charsetName);
}

int compare(int *a, int *b){
	return (*a) - (*b);
}

//传入数组
JNIEXPORT void JNICALL Java_com_ethanco_jni_JniTest_giveArray
(JNIEnv *env, jobject jobj, jintArray arr){
	//jintArray -> jnit指针 -> c int 数组
	jint *elems = (*env)->GetIntArrayElements(env, arr, JNI_FALSE); //JNI_FALSE: 最后可通过ReleaseIntArrayElements将该数组同步到Java
	//数组的长度
	int len = (*env)->GetArrayLength(env, arr);
	//排序
	qsort(elems, len, sizeof(jint), compare);

	//同步到Java
	//mode
	//0: Java数组进行更新，并且释放C/C++数组
	//JNI_ABORT : 对Java数组不更新，但是释放C/C++数组
	//JNI_COMMIT:对JAVA数组进行更新，不释放C/C++数组 (函数执行完，数组还是会释放)
	(*env)->ReleaseIntArrayElements(env, arr, elems, JNI_COMMIT);
}

//返回数组
JNIEXPORT jintArray JNICALL Java_com_ethanco_jni_JniTest_getArray
(JNIEnv *env, jobject jobj,jint len){
	//创建一个指定大小的数组
	jintArray jint_arr = (*env)->NewIntArray(env, len);
	jint *elems = (*env)->GetIntArrayElements(env, jint_arr, NULL);
	for (int i = 0; i < len; i++)
	{
		elems[i] = i;
	}

	//同步到Java
	(*env)->ReleaseIntArrayElements(env, jint_arr, elems, 0);
	return jint_arr;
}

/*
* JNI 引用变量
* 引用类型: 局部引用和全局引用
* 作用:在JNI中告知JAVA虚拟机合适回收一个JNI变量

	局部引用，通过DeleteLocalRef手动释放对象
	1.访问一个很大的Java对象，使用完之后，还要进行复杂的耗时操作
	2.创建了大量的局部引用，占用了太多的内存，而且这些局部引用跟后面的操作没有关联性
*/
//模拟创建数组
JNIEXPORT void JNICALL Java_com_ethanco_jni_JniTest_localRef(JNIEnv *env,jobject jobj)
{
	for (int i = 0; i < 5; i++)
	{
		//创建Date对象
		jclass cls = (*env)->FindClass(env, "java/util/Date");
		jmethodID constructor_mid = (*env)->GetMethodID(env, cls, "<init>", "()V");
		jobject obj = (*env)->NewObject(env, cls, constructor_mid);
		//此处省略一万行代码....

		//不再使用jobject对象了
		//通知垃圾回收器回收这些对象
		(*env)->DeleteLocalRef(env, obj);

		//此处省略一万行代码
	}
}

//全局引用
//共享(可以跨线程，要自己处理线程安全的问题)，手动控制内存使用
jstring global_str;

//创建
JNIEXPORT void JNICALL Java_com_ethanco_jni_JniTest_createGlobalRef(JNIEnv *env, jobject jobj){
	jstring obj = (*env)->NewStringUTF(env, "jni development is powerful !");
	global_str = (*env)->NewGlobalRef(env, obj);
}

//获取
JNIEXPORT jstring JNICALL Java_com_ethanco_jni_JniTest_getGlobalRef(JNIEnv *env, jobject jobj){
	return global_str;
}

//释放
JNIEXPORT void JNICALL Java_com_ethanco_jni_JniTest_deleteGlobalRef(JNIEnv *env, jobject jobj){
	(*env)->DeleteGlobalRef(env, global_str);
}

//弱全局引用
//节省内存，在内存不足时释放所引用的对象
//什么时候用:  可以引用一个不常用的对象，如果为NULL、被释放，那就临时创建
//创建:NewWeakGlobalRef 销毁:DeleteGlobalWeakRef

//异常处理
//1.保证Java代码可以运行
//2.补救措施保证C代码继续运行

//JNI自己抛出的Exception异常，在Java层无法被捕捉，只能在C层清空 (Error异常可以被捕捉)
//用户通过ThrowNew抛出的异常，可以在Java层捕捉
JNIEXPORT void JNICALL Java_com_ethanco_jni_JniTest_exeception(JNIEnv *env, jobject jobj){
	jclass cls = (*env)->GetObjectClass(env, jobj);
	jfieldID fid = (*env)->GetFieldID(env, cls, "key2", "Ljava/lang/String;");
	//检测是否发生Java异常
	jthrowable exception = (*env)->ExceptionOccurred(env);
	if (exception != NULL){
		//让Java代码可以继续运行
		//清空异常信息
		(*env)->ExceptionClear(env);

		//补救措施
		fid = (*env)->GetFieldID(env, cls, "key", "Ljava/lang/String;");
	}

	//获取属性的值
	jstring jstr = (*env)->GetObjectField(env, jobj, fid);
	//参数三: jboolean指针类型 函数内会赋值这个传参，复制了isCopy为JNI_TRUE，没复制为JNI_FALSE
	//意义，isCopy为JNI_FALSE，c_str和jstr都是指向同一个字符串，不能修改java字符串
	jboolean isCody =NULL;
	char *str = (*env)->GetStringUTFChars(env, jstr, isCody);
	//只要使用GetStringUTFChars，需要释放 	//(*env)->ReleaseStringUTFChars(env, jstr, str);

	//对比属性值是否合法
	printf("jstr------->>>:%#s\n", str);
	if (stricmp(str, "super jason1") != 0){ //super jason是正确的，这里模拟值错误，使用super jason1比较
		//认为抛出异常，给Java层处理
		jclass newExcCls = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
		(*env)->ThrowNew(env, newExcCls, "key's value is invalid!");
	}

	//释放，(只要使用GetStringUTFChars，需要释放)
	(*env)->ReleaseStringUTFChars(env, jstr, str);
}

	//缓存策略

	//static jfieldID key_id; //局部静态变量
	JNIEXPORT void JNICALL Java_com_ethanco_jni_JniTest_cached(JNIEnv *env, jobject jobj){
		jclass cls = (*env)->GetObjectClass(env, jobj);
		//获取jfiledID 只获取一次
		static jfieldID key_id = NULL; //static 局部静态变量，会一直存到程序结束，但只有这个方法内能够使用
		if (key_id==NULL)
		{
			key_id = (*env)->GetFieldID(env, cls, "key", "Ljava/lang/String;");
			printf("-------------GetFiledID-----------------\n");
		}
	}

	//初始化全局变量，动态库加载完成之后，立刻缓存起来
	jfieldID key_fid;
	jmethodID random_mid;
	JNIEXPORT void JNICALL Java_com_ethanco_jni_JniTest_initIds(JNIEnv *env, jclass jcls){
		key_fid = (*env)->GetFieldID(env, jcls, "key", "Ljava/lang/String;");
		random_mid = (*env)->GetMethodID(env, jcls, "getRandomInt", "(I)I");
	}

//其他详解Java Native Interface Specification.CHM文档