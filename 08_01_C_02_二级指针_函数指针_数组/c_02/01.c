#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>  //���Ե���
#include <math.h> //���������
#include <time.h> //ʱ��

/*
1.ָ��ΪʲôҪ������?
ָ�������ͣ�����ַû�����͡�
��ַֻ�Ǽ�¼��ʼ��λ�ã����͸��߶�ȡ��ʲôλ�ý���
(int* ��ȡ4�ֽڣ�double* ��ȡ8�ֽ�)
*/
void method1(){
	int i = 89;
	int *p = &i;
	double j = 78.9; //double8�ֽ�
	p = &j; //��ͨ��3�ֽڶ�ȡ8�ֽڱ�����ֵ���ǲ��е�

	printf("%#x , %1f\n", p, *p);
	getchar();
}

/*
2.��ָ��: NULL
��ָ���ڴ��ַΪ0���ڴ��ַΪ0x000000
*/
void method2(){
	int i = 9;
	int *p = NULL; //��ָ��
	//p = &i;
	
	p = 100; //��Ҫ����ָ�븳ֵΪ��������ı���ָ��洢���ڴ��ַ���������ַ���п���������Ӧ�ú�ϵͳ���ڴ�

	printf("%d\n", *p);
	getchar();
}

/*
3.�༶ָ��(����ֻ������ָ��)
ָ�뱣����Ǳ����ĵ�ַ��������������������һ��ָ�����
*/
void method3(){
	int a = 50;
	//p1�ϱ����a�ĵ�ַ
	int*p1= &a;
	//p2�ϱ����p1�ĵ�ַ
	int** p2 = &p1; //����ָ��
	//p3�ϱ����p2�ĵ�ַ
	//int*** p3 = &p2; //����ָ��

	printf("p1:%#x,p2:%#x\n", p1, *p2);
	printf("p1:%#x,p2:%#x,a:%#x\n", &p1, &p2,&a);
	//�ı�a��ֵ
	//**p2 = 90;

	printf("%d\n", a);

	getchar();
}

/*
4.ָ�������
һ�����������ʱ�������壬�����������ڴ����������еķ�ʽ
*/
void method4(){
	int ids[] = { 78, 90, 23, 65, 19 };
	//ids��&ids[0]����ĵ�ַ��ͬ��ids�������ݵ��׵�ַ
	printf("%#x\n", ids);
	printf("%#x\n", &ids);
	printf("%#x\n", &ids[0]);
	//ָ�����
	int *p = ids;
	printf("%d\n", *p);
	//ָ��ļӷ� ָ����ǰ�ƶ�sizeof(��������)���ֽ�
	p++;
	//p = p + 2;
	printf("p��ֵ:%#x\n", p);
	printf("%d\n", *p);

	getchar();
}

/*
5.ͨ��ָ������鸳ֵ
*/
void method5(){
	int uids[5];
	int* p = uids;
	
	/* �߼�д��
	for (int i = 0; i < 5; i++){
		uids[i] = i;
	}*/

	/*��Щ�汾��д��
	
	*/
	int i = 0;
	for (; p < uids+5; p++){ //p < uids+5 �Ƚϵ�ַ   p++: pָ����ǰ�ƶ��������͸��ֽ�
		*p = i;
		i++;
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", uids[i]);
	}

	getchar();
}

/*
6.����ָ��
*/
void msg(char* msg,char* title){
	MessageBox(0, msg, title, 0); //������ʾ��
}

void method6(){
	printf("%#x\n", msg);
	printf("%#x\n", &msg);

	/*����ָ��
	void�������ķ���ֵ
	fun_p:����ָ�������
	char* msg, char* title: �����Ĳ����б�
	*/
	void(*fun_p)(char* msg, char* title) = msg;  
	fun_p("��Ϣ����", "����");
	getchar();
}

/*
7.����ָ�� ʵս
*/
int add(int a, int b){
	return a + b;
}

int minus(int a, int b){
	return a - b;
}

//�˺�����Ҫ����һ������ָ�����
//����ִ�в�ͬ�ĺ���
void msg2(int(*func_p2)(int a,int b),int m,int n){
	//ִ��һ�δ���
	m++;
	//ִ�лص�����
	int r = func_p2(m, n);
	printf("%d\n", r);
}

void method7(){
	msg2(add, 10, 20); //�ӷ�
	msg2(minus, 50, 10); //����
	getchar();
}

/*
8.�����д��
*/
void method8(){
	//�׵�ַ
	//a+i �ȼ��� &a[i]�� *(a+i)�ȼ���a[i] �� ����ֻ�Ǽ�д��ʽ������ϵ�C��������û�������ŵ�
}

/*
9.��ϰ: �����������һ�����飬дһ������������С��ֵ����������С���ĵ�ַ�����������д�ӡ����   
*/
int* getMinPointer(int ids[], int len){
	int i = 0;
	int *p = &ids[0];
	for (i = 0; i < len; i++){
		if (ids[i]<*p){
			//*p = ids[i]; //��ֵֵ
			p = &ids[i]; //��ֵ��ַ
		}
	}
	return p;
}

void method9(){
	int ids[10];
	int i = 0;
	//��ʼ����������������������ӣ����Ӳ�һ����������Ų�һ��
	//��ǰʱ����Ϊ����
	srand(time(NULL));
	for (i = 0; i < 10; i++)
	{
		ids[i] = rand() % 100;
		printf("%d\n", ids[i]);
	}

	int arrayLength = sizeof(ids) / sizeof(int); //��ȡ���鳤��
	int* p = getMinPointer(ids, arrayLength);
	printf("%#x,%d\n", p, *p);
	getchar();
}

void method10(){

}

void main(){
	//method1();
	//method2();
	//method3();
	//method4();
	//method5();
	//method6();
	//method7();
	//method9();
	method10();
}