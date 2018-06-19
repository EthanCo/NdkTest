#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

/*
静态内存分配
*/
void mthdod1(){
	//10M
	//会报错: stack overflow错误，栈溢出
	//静态内存分配
	int a[1024 * 1024 * 10];

	//C语言内存分配
	//1.栈区(statck)，windows下，栈内存分配比如2M (确定的常数)，超出了限制，就会提示stack overflow错误
	//栈内存自动分配，释放。
	//2.堆区(heap)
	//程序员手动分配和释放，可以分配操作系统大概80%的内存
	//3.全局区或者叫静态区
	//4.字符常量区
	//5.程序代码区

	getchar();
}

/*
栈内存分配
*/
void method1_1(){
	int a[1024];  //自动释放
}

/*
堆内存分配
*/
void method2(){
	//在堆内存上，分配40M的内存
	//malloc返回值是void * ，可以是任意类型的指针
	//int* p = malloc(1024 * 1024 * 10 * sizeof(int)); //动态分配，sizeof(int)提升代码可读性
	float* p = malloc(1024 * 1024 * 10 * sizeof(float)); 
	Sleep(1000*10);
	//释放
	free(p);

	getchar();
}

/*
创建一个数组，动态制定数组的大小
(在程序运行过程中，可以随意的开辟制定大小的内存，以供使用，相当于Java中的集合)

动态内存分配和静态内存分配的区别?
静态内存分配
分配内存的大小是固定的，程序还没运行的时候，就知道要开辟多大的栈内存区域。
缺点: 1. 很容易超出栈内存的最大量
2.为了防止内存不够用，会开辟更多的内存，容易浪费内存

动态内存分配
在程序运行过程中动态指定需要使用的内存大小，手动释放，释放之后，这些内存还可以内重新使用。
*/
void method3(){
	//静态内存分配创建数组，数组的大小是固定的
	//int a[10];

	int len;
	printf("输入数组的长度:");
	scanf("%d", &len);

	//开辟内存，大小是len*4字节
	int* p = malloc(len * sizeof(int));

	//p是数组的首地址，p就是数组的名称
	//给数组元素赋值 (使用这一块刚刚开辟出来的内存区域)
	for (int i = 0; i < len; i++)
	{
		p[i] = rand() % 100;
		printf("%d,%#x\n", p[i], &p[i]);
	}

	//手动释放内存
	free(p);

	getchar();
}

/*
动态内存分配: 扩大内存大小 realloc
*/
void method4(){
	int len;
	printf("第一次输入数组的长度:");
	scanf("%d", &len);
	int* p = malloc(len * sizeof(int));
	//int* p = calloc(len, sizeof(int)); //malloc和calloc作用一样，colloc不用自己计算，一般使用malloc即可

	for (int i = 0; i < len; i++)
	{
		p[i] = rand() % 100;
		printf("%d,%#x\n", p[i], &p[i]);
	}

	int addLen;
	printf("输入数组增加的长度(可输入负数，释放部分内存):");
	scanf("%d", &addLen);
	//扩大刚刚分配的内存空间
	//参数1.原来内存的指针 参数2.内存扩大之后的总大小
	int* p2 = realloc(p, sizeof(int)*(len + addLen));
	if (p2==NULL)
	{
		printf("重新分配内存失败...........");
	}
	/*
	重新分配内存的两种情况
	如果是缩小的情况下，缩小的那部分数据会丢失
	如果是扩大的情况下
	1.如果当前内存段后面有需要的内存空间，直接扩展这段内存空间，realloc返回原指针
	2.如果当前内存段后面的空闲字节不够(已经被其他程序所使用了)，那么就使用堆中第一个能够满足这一要求的内存块，将目前的数据复制到新的位置，并将原来的数据库释放掉，返回新的内存地址。
	3.如果申请失败(没有那么大的内存)，返回NULL，原来的指针任然有效
	*/


	printf("--------------------------------------------------------\n");

	//重新赋值
	for (int i = 0; i < len+addLen; i++)
	{
		p2[i] = rand() % 100;
		printf("%d,%#x\n", p2[i], &p2[i]);
	}

	//手动释放内存
	if (p!=NULL)
	{
		free(p);
		p = NULL;
	}
	if (p2!=NULL)
	{
		free(p2);
		p = NULL;
	}

	getchar();
	getchar();
}

/*
内存分配的几个注意细节
1.不能多次释放 free()
2.释放完之后，给指针置NULL，标志释放完成
3.内存泄露(p重新赋值之后，再free，并没有真正释放内存)  -------<<<<<<<<<<< [很重要]
	重新赋值前，要把p先释放掉再赋值，否则会内存泄露 !!! 
*/
void method5(){
	int len;
	printf("输入数组的长度:");
	scanf("%d", &len);

	int* p = malloc(len * sizeof(int));

	//重新赋值前，要把p先释放掉再赋值
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}

	p = malloc(2* len * sizeof(int));

	for (int i = 0; i < len; i++)
	{
		p[i] = rand() % 100;
		printf("%d,%#x\n", p[i], &p[i]);
	}

	if (p != NULL)
	{
		free(p); 
		//free(p); //不能多次释放 free()
		p = NULL; //释放完之后，给指针置NULL，标志释放完成
	}
	

	getchar();
}

void main(){
	//mthdod1();
	//method2();
	//method3();
	//method4();
	method5();
}