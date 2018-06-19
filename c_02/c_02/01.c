#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>  //可以弹框
#include <math.h> //包含随机数
#include <time.h> //时间

/*
1.指针为什么要有类型?
指针有类型，而地址没有类型。
地址只是记录开始的位置，类型告诉读取到什么位置结束
(int* 读取4字节，double* 读取8字节)
*/
void method1(){
	int i = 89;
	int *p = &i;
	double j = 78.9; //double8字节
	p = &j; //想通过3字节读取8字节变量的值，是不行的

	printf("%#x , %1f\n", p, *p);
	getchar();
}

/*
2.空指针: NULL
空指针内存地址为0，内存地址为0x000000
*/
void method2(){
	int i = 9;
	int *p = NULL; //空指针
	//p = &i;
	
	p = 100; //不要随便给指针赋值为整数，这改变了指针存储的内存地址，而这个地址极有可能是其他应用和系统的内存

	printf("%d\n", *p);
	getchar();
}

/*
3.多级指针(这里只讲二级指针)
指针保存的是变量的地址，保存的这个变量可以是一个指针变量
*/
void method3(){
	int a = 50;
	//p1上保存的a的地址
	int*p1= &a;
	//p2上保存的p1的地址
	int** p2 = &p1; //二级指针
	//p3上保存的p2的地址
	//int*** p3 = &p2; //三级指针

	printf("p1:%#x,p2:%#x\n", p1, *p2);
	printf("p1:%#x,p2:%#x,a:%#x\n", &p1, &p2,&a);
	//改变a的值
	//**p2 = 90;

	printf("%d\n", a);

	getchar();
}

/*
4.指针的运算
一般在数组遍历时才有意义，基于数组在内存中线性排列的方式
*/
void method4(){
	int ids[] = { 78, 90, 23, 65, 19 };
	//ids和&ids[0]输出的地址相同，ids就是数据的首地址
	printf("%#x\n", ids);
	printf("%#x\n", &ids);
	printf("%#x\n", &ids[0]);
	//指针变量
	int *p = ids;
	printf("%d\n", *p);
	//指针的加法 指针向前移动sizeof(数据类型)个字节
	p++;
	//p = p + 2;
	printf("p的值:%#x\n", p);
	printf("%d\n", *p);

	getchar();
}

/*
5.通过指针给数组赋值
*/
void method5(){
	int uids[5];
	int* p = uids;
	
	/* 高级写法
	for (int i = 0; i < 5; i++){
		uids[i] = i;
	}*/

	/*早些版本的写法
	
	*/
	int i = 0;
	for (; p < uids+5; p++){ //p < uids+5 比较地址   p++: p指针向前移动数据类型个字节
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
6.函数指针
*/
void msg(char* msg,char* title){
	MessageBox(0, msg, title, 0); //弹出提示框
}

void method6(){
	printf("%#x\n", msg);
	printf("%#x\n", &msg);

	/*函数指针
	void代表函数的返回值
	fun_p:函数指针的名称
	char* msg, char* title: 函数的参数列表
	*/
	void(*fun_p)(char* msg, char* title) = msg;  
	fun_p("消息内容", "标题");
	getchar();
}

/*
7.函数指针 实战
*/
int add(int a, int b){
	return a + b;
}

int minus(int a, int b){
	return a - b;
}

//此函数需要传递一个函数指针参数
//可以执行不同的函数
void msg2(int(*func_p2)(int a,int b),int m,int n){
	//执行一段代码
	m++;
	//执行回调函数
	int r = func_p2(m, n);
	printf("%d\n", r);
}

void method7(){
	msg2(add, 10, 20); //加法
	msg2(minus, 50, 10); //减法
	getchar();
}

/*
8.数组的写法
*/
void method8(){
	//首地址
	//a+i 等价于 &a[i]， *(a+i)等价于a[i] 。 后者只是简写方式，最古老的C语言里是没有中括号的
}

/*
9.练习: 用随机数生成一个数组，写一个函数查找最小的值，并返回最小数的地址，在主函数中打印出来   
*/
int* getMinPointer(int ids[], int len){
	int i = 0;
	int *p = &ids[0];
	for (i = 0; i < len; i++){
		if (ids[i]<*p){
			//*p = ids[i]; //赋值值
			p = &ids[i]; //赋值地址
		}
	}
	return p;
}

void method9(){
	int ids[10];
	int i = 0;
	//初始化随机数发生器，设置种子，种子不一样，随机数才不一样
	//当前时间作为种子
	srand(time(NULL));
	for (i = 0; i < 10; i++)
	{
		ids[i] = rand() % 100;
		printf("%d\n", ids[i]);
	}

	int arrayLength = sizeof(ids) / sizeof(int); //获取数组长度
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