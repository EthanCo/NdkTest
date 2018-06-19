#define _CRT_SECURE_NO_WARNINGS //宏定义

//引入头文件
//这里只有函数的声明，函数的实现是在编译的时候，他会去找我们函数(printf)的实现，替换到printf的位置上
#include <stdio.h> //包含printf
#include <stdlib.h> //包含scanf
#include <Windows.h> //window特有的函数

//打印
void printTest(){
	/*
	在不同的平台下面，比如Win7下打包生成exe，winXP不一定能运行。 (win7和winXP的指令不一定相同) printf 的实现就不一样
	*/
	printf("hello world\n");
}

//占位符
void placeholderTest(){
	/*
	%d 十进制整数
	%s 读入一个字符串，遇到空格、制表符或换行符结束
	%f %F 小数 float

	%i  十进制、八进制、十六进制整数
	%x %X 十六进制整数
	%p 读入一个指针
	*/
	int i = 1;
	printf("%d\n", i);
	float f = 23.3;
	printf("%f\n", f);
	printf("int占%d字节\n", sizeof(int));
	printf("char占%d字节\n", sizeof(char));
	printf("float占%d字节\n", sizeof(float));
	printf("double占%d字节\n", sizeof(double));
}

//输入
void scanfTest(){
	int i;
	printf("请输入一个整数");
	//赋值
	scanf("%d", &i); //&value 控制台输入，&取地址符
	//打印
	printf("i的值为:%d\n", i);
	system("pause");//getchar();
}

//指针
void pointerTest(){
	//指针存储的是变量的内存地址
	/*
	内存地址，系统给数据分配的编号
	*/
	//变量名，对内存空间上的一段数据的抽象
	int i = 90;
	//指针变量，创建一个int类型的指针
	int* p = &i; //p的值就是这个变量的内存地址
	printf("%#x\n", p); //%#x会输出0x开头的16进制
	//float p = 89.5f;
	//float *fp = &p;
	//printf("%#x\n", fp);

	printf("改之前，i的值为:%d\n", i);
	printf("改之前，p的值为:%#d\n", *p);
	printf("改之前，i的地址为:%#x\n", &i);
	printf("改之前，p的地址为:%#x\n", &p);
	//间接赋值，i = 200;  
	*p = 200;
	printf("改之后，i的值为:%d\n", i);
	printf("改之后，p的值为:%#x\n", p);
	printf("改之后，p指向的值为:%#d\n", *p);
	printf("改之后，i的地址为:%#x\n", &i);
	printf("改之后，p的地址为:%#x\n", &p);
	system("pause");
}

//游戏外挂
//可通过类似0x45f76c的地址，赋值给指针，从而修改time的值
void externalTest(){
	int time = 600;
	printf("time:%#x\n", &time);
	while (time > 0){
		time--;
		printf("游戏剩余时间%d\n", time);
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



