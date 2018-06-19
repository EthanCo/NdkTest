#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

//使用字符数组来存储字符串
void method1(){
//char str[] = { 'c', 'h', 'i', 'n', 'a' ,'\0'};
//char str[6] = { 'c', 'h', 'i', 'n', 'a' };
char str[10] = "china";
str[0] = 's';
printf("%s\n", str);
printf("%#x\n", str);
getchar();
}

//字符指针
void method2(){
	//内存连续排列
	char * str = "how are you?"; 

	str += 1; //向前移一位

	//和Java一样，有专门存放字符串的区域，无法修改
	//str[0] = 'w'; 
	//*str = "hello";

	printf("%s\n", str);
	printf("%#x\n", str);
	getchar();
}

//字符串相关函数
//在线API文档：http://www.kuqin.com/clib/string/strcpy.html
void method3(){
	char dest[50];
	char *a = "china";
	char *b = " is powerful!";
	strcpy(dest, a);
	strcat(dest, b);
	printf("%s\n", dest);

	system("pause");
}

//strchr在一个串中查找给定字符的第一个匹配之处
void method4(){
char *str = "I want go to USA!";
printf("%#x\n", str);
//U元素的指针
//str+3
char* p = strchr(str, 'w');
if (p){
printf("索引位置：%d\n", p - str);
}
else{
printf("没有找到");
}

system("pause");
}

void main(){
	//method1();
	//method2();
	//method3();
	method4();
}