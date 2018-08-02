#define _CRT_SECURE_NO_WARNINGS //�궨��

//����ͷ�ļ�
//����ֻ�к�����������������ʵ�����ڱ����ʱ������ȥ�����Ǻ���(printf)��ʵ�֣��滻��printf��λ����
#include <stdio.h> //����printf
#include <stdlib.h> //����scanf
#include <Windows.h> //window���еĺ���

//��ӡ
void printTest(){
	/*
	�ڲ�ͬ��ƽ̨���棬����Win7�´������exe��winXP��һ�������С� (win7��winXP��ָ�һ����ͬ) printf ��ʵ�־Ͳ�һ��
	*/
	printf("hello world\n");
}

//ռλ��
void placeholderTest(){
	/*
	%d ʮ��������
	%s ����һ���ַ����������ո��Ʊ�����з�����
	%f %F С�� float

	%i  ʮ���ơ��˽��ơ�ʮ����������
	%x %X ʮ����������
	%p ����һ��ָ��
	*/
	int i = 1;
	printf("%d\n", i);
	float f = 23.3;
	printf("%f\n", f);
	printf("intռ%d�ֽ�\n", sizeof(int));
	printf("charռ%d�ֽ�\n", sizeof(char));
	printf("floatռ%d�ֽ�\n", sizeof(float));
	printf("doubleռ%d�ֽ�\n", sizeof(double));
}

//����
void scanfTest(){
	int i;
	printf("������һ������");
	//��ֵ
	scanf("%d", &i); //&value ����̨���룬&ȡ��ַ��
	//��ӡ
	printf("i��ֵΪ:%d\n", i);
	system("pause");//getchar();
}

//ָ��
void pointerTest(){
	//ָ��洢���Ǳ������ڴ��ַ
	/*
	�ڴ��ַ��ϵͳ�����ݷ���ı��
	*/
	//�����������ڴ�ռ��ϵ�һ�����ݵĳ���
	int i = 90;
	//ָ�����������һ��int���͵�ָ��
	int* p = &i; //p��ֵ��������������ڴ��ַ
	printf("%#x\n", p); //%#x�����0x��ͷ��16����
	//float p = 89.5f;
	//float *fp = &p;
	//printf("%#x\n", fp);

	printf("��֮ǰ��i��ֵΪ:%d\n", i);
	printf("��֮ǰ��p��ֵΪ:%#d\n", *p);
	printf("��֮ǰ��i�ĵ�ַΪ:%#x\n", &i);
	printf("��֮ǰ��p�ĵ�ַΪ:%#x\n", &p);
	//��Ӹ�ֵ��i = 200;  
	*p = 200;
	printf("��֮��i��ֵΪ:%d\n", i);
	printf("��֮��p��ֵΪ:%#x\n", p);
	printf("��֮��pָ���ֵΪ:%#d\n", *p);
	printf("��֮��i�ĵ�ַΪ:%#x\n", &i);
	printf("��֮��p�ĵ�ַΪ:%#x\n", &p);
	system("pause");
}

//��Ϸ���
//��ͨ������0x45f76c�ĵ�ַ����ֵ��ָ�룬�Ӷ��޸�time��ֵ
void externalTest(){
	int time = 600;
	printf("time:%#x\n", &time);
	while (time > 0){
		time--;
		printf("��Ϸʣ��ʱ��%d\n", time);
		Sleep(1000);
	}
}

void main(){
	//printTest();
	//placeholderTest();
	//scanfTest();
	pointerTest();
	//externalTest();
}



