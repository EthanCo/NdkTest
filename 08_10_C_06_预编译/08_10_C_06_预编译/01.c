#include <stdlib.h>
#include <stdio.h>

#include "A.h"
#include "B.h"

/*
C����ִ�е�����
Ԥ����׶ϣ����������Щ#includeɶ�ġ�
����׶ϣ���C���ԵĴ���ת�ɻ�����Դ��룬���� int a = 2; ��������mov a, 2;
���׶ϣ��ѻ�����ת���ɻ����룬�����mov a , 2 ; ת�� cd07 (movָ��Ļ������е�һ�ֻ����룩
���ӽ׶ϣ�������һ����ִ���ļ�������windows��PE�Ŀ�ִ���ļ�,linux��elf�Ŀ�ִ���ļ���Ҫ�����ɿ������еĳ���

//Ԥ����(Ԥ����)��Ϊ������׼����������ɴ����ı����滻����

ͷ�ļ����߱�����������һ�������������������ҵ����������ʵ��
*/

void method1(){
	//#include "my.txt" //Ԥ����׶λ��滻Ϊ printf("%s\n","I am a boy!");
	getchar();
}

/*
defineָ�� (�궨�塢���滻��Ԥ����ָ��)
1.�����ʶ
#ifdef __cplusplus ��ʾ������֧��C++�﷨
��ֹ�ļ��ظ�����(ѭ�����ã���ֹA.h����B.h��ͬʱB.h����A.h)
2.���峣�� (�����޸ĺ��Ķ�)������Ԥ����׶ν����滻
#define MAX 100
3.����"�꺯��"
*/

void method2(){
	//printfA();
	//printfB();
	getchar();
}

//���峣�� 
#define MAX 100

void dn_com_jni_read(){
	printf("read\n");
}

void dn_com_jni_write(){
	printf("write\n");
}
//����"�꺯��"
//NAME�ǲ���
#define mytest(NAME) dn_com_jni_##NAME();
//�������ƺܳ������ú꺯�����̺�������

//�꺯��ʵ�� -> ��־���
//__VA_ARGS__�ɱ����
#define LOG(TAG,...) printf(##TAG,__VA_ARGS__);  //##������� (��ʱ�򲻼�Ҳ����)

void method3(){
	mytest(write);
	getchar();
}

void method4(){
	LOG("%s%d", "��С��", 89);
	getchar();
}

//������ ��־ (�滻����)
#define LOG(LEVEL,FORMAT,...) printf(##LEVEL); printf(##FORMAT,__VA_ARGS__);
#define LOG_I(FORMAT,...) LOG("INFO:",##FORMAT,__VA_ARGS__);
#define LOG_E(FORMAT,...) LOG("ERROR:",##FORMAT,##__VA_ARGS__);   //##������� (��ʱ�򲻼�Ҳ����)
#define LOG_W(FORMAT,...) LOG("WARN:",##FORMAT,__VA_ARGS__);

void method5(){
	LOG_E("%s%d", "��С��", 90);
	getchar();
}

void main(){
	//method1();
	//method2();
	//method3();
	//method4();
	method5();
}