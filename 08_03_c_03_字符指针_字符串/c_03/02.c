#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

//ʹ���ַ��������洢�ַ���
void method1(){
//char str[] = { 'c', 'h', 'i', 'n', 'a' ,'\0'};
//char str[6] = { 'c', 'h', 'i', 'n', 'a' };
char str[10] = "china";
str[0] = 's';
printf("%s\n", str);
printf("%#x\n", str);
getchar();
}

//�ַ�ָ��
void method2(){
	//�ڴ���������
	char * str = "how are you?"; 

	str += 1; //��ǰ��һλ

	//��Javaһ������ר�Ŵ���ַ����������޷��޸�
	//str[0] = 'w'; 
	//*str = "hello";

	printf("%s\n", str);
	printf("%#x\n", str);
	getchar();
}

//�ַ�����غ���
//����API�ĵ���http://www.kuqin.com/clib/string/strcpy.html
void method3(){
	char dest[50];
	char *a = "china";
	char *b = " is powerful!";
	strcpy(dest, a);
	strcat(dest, b);
	printf("%s\n", dest);

	system("pause");
}

//strchr��һ�����в��Ҹ����ַ��ĵ�һ��ƥ��֮��
void method4(){
char *str = "I want go to USA!";
printf("%#x\n", str);
//UԪ�ص�ָ��
//str+3
char* p = strchr(str, 'w');
if (p){
printf("����λ�ã�%d\n", p - str);
}
else{
printf("û���ҵ�");
}

system("pause");
}

void main(){
	//method1();
	//method2();
	//method3();
	method4();
}