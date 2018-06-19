#define _CRT_SECURE_NO_WARNINGS
#include "com_ethanco_jni_JniTest.h"
#include <string.h>
#include <stdio.h> 
#include <stdlib.h> 

//����ʵ��
JNIEXPORT jstring JNICALL Java_com_ethanco_jni_JniTest_getStringFromC
(JNIEnv *env, jclass jcls){
	//�򵥵�ʵ��
	//��C���ַ���תΪһ��java�ַ���
	return (*env)->NewStringUTF(env, "C String");
}

JNIEXPORT jstring JNICALL Java_com_ethanco_jni_JniTest_getStringFromC2
(JNIEnv *env, jobject jcls){
	return (*env)->NewStringUTF(env,"C String 2");
}

//ÿ��native����������������������(JNIEnv*,jclass����jobject)
//��native����(Java����)����̬����ʱ:       jclass ����native����(Java����)�������class���� (JniTest.class)
//��native����(Java����)����Ǿ�̬����ʱ:     jobject ����native����(Java����)�������class���� (JniTest.class)


//��������
//Java��������������JNI�������͵�ӳ���ϵ
//Java����->JNI����->C����
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

//��������(����)
//String jstring
//object jobject
//����,�����������͵�����
//byte[] jByteArray
//��������
//object[](String[]) jobjectArray

//C/C++����java
//�޸�Java�����Բ�����
JNIEXPORT jstring JNICALL Java_com_ethanco_jni_JniTest_accessField
(JNIEnv *env, jobject jobj){
	//�õ�jclass   jobj��t����JniTest.class
	jclass cls = (*env)->GetObjectClass(env, jobj);
	//�õ���������      ����ǩ�� ---->> (���Java�����뷽��ǩ���б�.png)
	jfieldID fid = (*env)->GetFieldID(env, cls, "key", "Ljava/lang/String;");
	//���key������ֵ
	jstring jstr = (*env)->GetObjectField(env, jobj, fid);
	//printf("jstr:%#x\n", &jstr); //��ӡ��־ EclipseҲ����ʾ�������ӳ٣���Java����
	//jason �ĳ� super jason   
	////������: jbooleanָ������ �����ڻḳֵ������Σ�������isCopyΪJNI_TRUE��û����ΪJNI_FALSE����ֱ�Ӵ�NULL
	char *c_str = (*env)->GetStringUTFChars(env, jstr, NULL); //�ȵõ�C���ַ��� (���������޸�)
	char text[20] = "super ";
	strcat(text, c_str); //ƴ�ӵõ��µ��ַ���

	jstring new_jstr = (*env)->NewStringUTF(env, text);

	//�޸�key
	(*env)->SetObjectField(env, jobj, fid, new_jstr);
	//printf("new_jstr:%#x\n", &new_jstr);
	return new_jstr;
}

//���ʾ�̬����
JNIEXPORT void JNICALL Java_com_ethanco_jni_JniTest_accessStaticField
(JNIEnv * env, jobject jobj){
	//��ȡjclass
	jclass cls = (*env)->GetObjectClass(env, jobj);
	jfieldID fid = (*env)->GetStaticFieldID(env, cls, "count", "I");
	//GetStatic<Type>Field
	jint count = (*env)->GetStaticIntField(env, cls, fid);
	count++;
	//�޸�
	//setSatatic<Type>Filed
	 (*env)->SetStaticIntField(env, cls, fid, count);
}

//����Java���� (���)
JNIEXPORT void JNICALL Java_com_ethanco_jni_JniTest_accessMethod
(JNIEnv * env, jobject jobj){
	jclass cls = (*env)->GetObjectClass(env, jobj);
	//ǩ����ȡ��ʽ java��ĿbinĿ¼��  javap -s -p ����.���� �� ���г��������з�����ǩ��������getRandomInt����(I)I
	//��ȡjmethodID ����ID
	jmethodID mid = (*env)->GetMethodID(env, cls, "getRandomInt", "(I)I");
	//���� Call<Type>Method
	jint random = (*env)->CallIntMethod(env, jobj, mid, 200); //jint��long ���ͣ�ȡ�ı���
	printf("random num:%ld", random);
}

//����Java��̬����
JNIEXPORT void JNICALL Java_com_ethanco_jni_JniTest_accessStaticMethod
(JNIEnv * env, jobject jobj){
	//jclass
	jclass cls = (*env)->GetObjectClass(env, jobj);
	//jmethodID
	jmethodID mid = (*env)->GetStaticMethodID(env, cls, "getUUID", "()Ljava/lang/String;"); //; �ֺű�����!!!!!
	//����
	//CallSatatic<Type>Method
	jstring uuid = (*env)->CallStaticObjectMethod(env, cls, mid);

	//����ļ�����
	//jstring -> char*
	////������: jbooleanָ������ �����ڻḳֵ������Σ�������isCopyΪJNI_TRUE��û����ΪJNI_FALSE����ֱ�Ӵ�NULL
	char *uuid_str = (*env)->GetStringUTFChars(env, uuid, NULL);
	//ƴ��
	char fileName[100];
	sprintf(fileName, "D://%s.txt", uuid_str); 
	FILE *fp = fopen(fileName, "w");
	fputs("i love jason", fp);
	fclose(fp);
}

//���ʹ��췽��
//ʹ��java.util.Date����һ����ǰ��ʱ���
JNIEXPORT jobject JNICALL Java_com_ethanco_jni_JniTest_accessConstructor
(JNIEnv *env, jobject jobj){
	jclass cls = (*env)->FindClass(env, "java/util/Date");
	//jmethodID�� "<init>" ���췽��
	jmethodID constructor_mid = (*env)->GetMethodID(env, cls, "<init>", "()V");
	//ʵ����һ��Date����
	jobject date_obj = (*env)->NewObject(env, cls, constructor_mid);
	//����getTime����
	jmethodID mid = (*env)->GetMethodID(env, cls, "getTime", "()J");
	jlong time = (*env)->CallLongMethod(env, date_obj, mid);

	printf("\ntime:%lld\n", time);
	return date_obj;
}

//���ø���ķ���
//��ȡjava�� public Human man = new Man(); �е�Human�������
JNIEXPORT void JNICALL Java_com_ethanco_jni_JniTest_accessNonvirtualMethod
(JNIEnv *env, jobject jobj){
	/*jclass cls = (*env)->GetObjectClass(env, jobj);
	//��ȡman����
	jfieldID fid = (*env)->GetFieldID(env, cls, "human", "Lcom/ethanco/jni/bean/Human;");
	//��ȡ
	jobject human_obj = (*env)->GetStaticObjectField(env, jobj, fid);

	//ִ��sayHi����
	jclass human_cls = (*env)->FindClass(env, "com/ethanco/jni/bean/Human");
	jmethodID mid = (*env)->GetMethodID(env, human_cls, "sayHi", "()V");

	//ִ��
	//(*env)->CallObjectMethod(env, human_obj, mid); //����������ķ���
	(*env)->CallNonvirtualObjectMethod(env, human_obj, human_cls, mid); //���ø���ķ���*/

	jclass cls = (*env)->GetObjectClass(env, jobj);
	//��ȡman���ԣ�����
	jfieldID fid = (*env)->GetFieldID(env, cls, "man001", "Lcom/ethanco/jni/bean/Human;");
	//��ȡ
	jobject human_obj = (*env)->GetObjectField(env, jobj, fid);

	//ִ��sayHi����
	jclass human_cls = (*env)->FindClass(env, "com/ethanco/jni/bean/Human"); //ע�⣺�����������
	jmethodID mid = (*env)->GetMethodID(env, human_cls, "sayHi", "()V");

	//ִ��
	//(*env)->CallObjectMethod(env, human_obj, mid);
	//���õĸ���ķ���
	(*env)->CallNonvirtualObjectMethod(env, human_obj, human_cls, mid);
}

//��java��stringת����c���ַ���
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
	(*env)->ReleaseByteArrayElements(env, barr, ba, 0);  //�ͷ��ڴ�ռ�
	return rtn;
}

//��������
JNIEXPORT jstring JNICALL Java_com_ethanco_jni_JniTest_chineseChars
(JNIEnv *env, jobject jobj, jstring in){
	//���
	//char *c_str = (*env)->GetStringUTFChars(env, in, NULL);
	//printf("%s\n", c_str);

	//jstring jstr = (*env)->NewStringUTF(env, c_str); ��Cֱ��ת�õ���UTF-8����java����������GB2312��������
	
	
	//˼·����Java�ķ�����ִ��
	//ִ��String(byte bytes[],String charsetName) ���췽����Ҫ������
	//1.jmethodID
	//2.byte����
	//3.�ַ�����jstring
	//char *c_str = "�������ν�";
	char *c_str = myJstring2CStr(env, in); //��java��stringת����c���ַ���
	printf("%s\n", c_str);

	jclass str_cls = (*env)->FindClass(env, "java/lang/String");
	jmethodID constructor_mid = (*env)->GetMethodID(env, str_cls, "<init>", "([BLjava/lang/String;)V");

	//jbyte -> char 
	//jbyteArray -> char[]
	jbyteArray bytes = (*env)->NewByteArray(env, strlen(c_str));
	//byte���鸳ֵ
	//0->strlen(c_str)����ͷ��β
	//�Ե��ڣ���c_str����ַ����飬���Ƶ�bytes����ַ�����
	(*env)->SetByteArrayRegion(env, bytes, 0, strlen(c_str), c_str);

	//�ַ�����jstring
	jstring charsetName = (*env)->NewStringUTF(env, "GB2312");

	//���ù��캯�������ر���֮���jstring
	return (*env)->NewObject(env, str_cls, constructor_mid, bytes, charsetName);
}

int compare(int *a, int *b){
	return (*a) - (*b);
}

//��������
JNIEXPORT void JNICALL Java_com_ethanco_jni_JniTest_giveArray
(JNIEnv *env, jobject jobj, jintArray arr){
	//jintArray -> jnitָ�� -> c int ����
	jint *elems = (*env)->GetIntArrayElements(env, arr, JNI_FALSE); //JNI_FALSE: ����ͨ��ReleaseIntArrayElements��������ͬ����Java
	//����ĳ���
	int len = (*env)->GetArrayLength(env, arr);
	//����
	qsort(elems, len, sizeof(jint), compare);

	//ͬ����Java
	//mode
	//0: Java������и��£������ͷ�C/C++����
	//JNI_ABORT : ��Java���鲻���£������ͷ�C/C++����
	//JNI_COMMIT:��JAVA������и��£����ͷ�C/C++���� (����ִ���꣬���黹�ǻ��ͷ�)
	(*env)->ReleaseIntArrayElements(env, arr, elems, JNI_COMMIT);
}

//��������
JNIEXPORT jintArray JNICALL Java_com_ethanco_jni_JniTest_getArray
(JNIEnv *env, jobject jobj,jint len){
	//����һ��ָ����С������
	jintArray jint_arr = (*env)->NewIntArray(env, len);
	jint *elems = (*env)->GetIntArrayElements(env, jint_arr, NULL);
	for (int i = 0; i < len; i++)
	{
		elems[i] = i;
	}

	//ͬ����Java
	(*env)->ReleaseIntArrayElements(env, jint_arr, elems, 0);
	return jint_arr;
}

/*
* JNI ���ñ���
* ��������: �ֲ����ú�ȫ������
* ����:��JNI�и�֪JAVA��������ʻ���һ��JNI����

	�ֲ����ã�ͨ��DeleteLocalRef�ֶ��ͷŶ���
	1.����һ���ܴ��Java����ʹ����֮�󣬻�Ҫ���и��ӵĺ�ʱ����
	2.�����˴����ľֲ����ã�ռ����̫����ڴ棬������Щ�ֲ����ø�����Ĳ���û�й�����
*/
//ģ�ⴴ������
JNIEXPORT void JNICALL Java_com_ethanco_jni_JniTest_localRef(JNIEnv *env,jobject jobj)
{
	for (int i = 0; i < 5; i++)
	{
		//����Date����
		jclass cls = (*env)->FindClass(env, "java/util/Date");
		jmethodID constructor_mid = (*env)->GetMethodID(env, cls, "<init>", "()V");
		jobject obj = (*env)->NewObject(env, cls, constructor_mid);
		//�˴�ʡ��һ���д���....

		//����ʹ��jobject������
		//֪ͨ����������������Щ����
		(*env)->DeleteLocalRef(env, obj);

		//�˴�ʡ��һ���д���
	}
}

//ȫ������
//����(���Կ��̣߳�Ҫ�Լ������̰߳�ȫ������)���ֶ������ڴ�ʹ��
jstring global_str;

//����
JNIEXPORT void JNICALL Java_com_ethanco_jni_JniTest_createGlobalRef(JNIEnv *env, jobject jobj){
	jstring obj = (*env)->NewStringUTF(env, "jni development is powerful !");
	global_str = (*env)->NewGlobalRef(env, obj);
}

//��ȡ
JNIEXPORT jstring JNICALL Java_com_ethanco_jni_JniTest_getGlobalRef(JNIEnv *env, jobject jobj){
	return global_str;
}

//�ͷ�
JNIEXPORT void JNICALL Java_com_ethanco_jni_JniTest_deleteGlobalRef(JNIEnv *env, jobject jobj){
	(*env)->DeleteGlobalRef(env, global_str);
}

//��ȫ������
//��ʡ�ڴ棬���ڴ治��ʱ�ͷ������õĶ���
//ʲôʱ����:  ��������һ�������õĶ������ΪNULL�����ͷţ��Ǿ���ʱ����
//����:NewWeakGlobalRef ����:DeleteGlobalWeakRef

//�쳣����
//1.��֤Java�����������
//2.���ȴ�ʩ��֤C�����������

//JNI�Լ��׳���Exception�쳣����Java���޷�����׽��ֻ����C����� (Error�쳣���Ա���׽)
//�û�ͨ��ThrowNew�׳����쳣��������Java�㲶׽
JNIEXPORT void JNICALL Java_com_ethanco_jni_JniTest_exeception(JNIEnv *env, jobject jobj){
	jclass cls = (*env)->GetObjectClass(env, jobj);
	jfieldID fid = (*env)->GetFieldID(env, cls, "key2", "Ljava/lang/String;");
	//����Ƿ���Java�쳣
	jthrowable exception = (*env)->ExceptionOccurred(env);
	if (exception != NULL){
		//��Java������Լ�������
		//����쳣��Ϣ
		(*env)->ExceptionClear(env);

		//���ȴ�ʩ
		fid = (*env)->GetFieldID(env, cls, "key", "Ljava/lang/String;");
	}

	//��ȡ���Ե�ֵ
	jstring jstr = (*env)->GetObjectField(env, jobj, fid);
	//������: jbooleanָ������ �����ڻḳֵ������Σ�������isCopyΪJNI_TRUE��û����ΪJNI_FALSE
	//���壬isCopyΪJNI_FALSE��c_str��jstr����ָ��ͬһ���ַ����������޸�java�ַ���
	jboolean isCody =NULL;
	char *str = (*env)->GetStringUTFChars(env, jstr, isCody);
	//ֻҪʹ��GetStringUTFChars����Ҫ�ͷ� 	//(*env)->ReleaseStringUTFChars(env, jstr, str);

	//�Ա�����ֵ�Ƿ�Ϸ�
	printf("jstr------->>>:%#s\n", str);
	if (stricmp(str, "super jason1") != 0){ //super jason����ȷ�ģ�����ģ��ֵ����ʹ��super jason1�Ƚ�
		//��Ϊ�׳��쳣����Java�㴦��
		jclass newExcCls = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
		(*env)->ThrowNew(env, newExcCls, "key's value is invalid!");
	}

	//�ͷţ�(ֻҪʹ��GetStringUTFChars����Ҫ�ͷ�)
	(*env)->ReleaseStringUTFChars(env, jstr, str);
}

	//�������

	//static jfieldID key_id; //�ֲ���̬����
	JNIEXPORT void JNICALL Java_com_ethanco_jni_JniTest_cached(JNIEnv *env, jobject jobj){
		jclass cls = (*env)->GetObjectClass(env, jobj);
		//��ȡjfiledID ֻ��ȡһ��
		static jfieldID key_id = NULL; //static �ֲ���̬��������һֱ�浽�����������ֻ������������ܹ�ʹ��
		if (key_id==NULL)
		{
			key_id = (*env)->GetFieldID(env, cls, "key", "Ljava/lang/String;");
			printf("-------------GetFiledID-----------------\n");
		}
	}

	//��ʼ��ȫ�ֱ�������̬��������֮�����̻�������
	jfieldID key_fid;
	jmethodID random_mid;
	JNIEXPORT void JNICALL Java_com_ethanco_jni_JniTest_initIds(JNIEnv *env, jclass jcls){
		key_fid = (*env)->GetFieldID(env, jcls, "key", "Ljava/lang/String;");
		random_mid = (*env)->GetMethodID(env, jcls, "getRandomInt", "(I)I");
	}

//�������Java Native Interface Specification.CHM�ĵ�