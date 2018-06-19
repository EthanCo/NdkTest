#include <stdlib.h>
#include <stdio.h>

#include "A.h"
#include "B.h"

/*
C语言执行的流程
预处理阶断：这个就是那些#include啥的。
编译阶断：把C语言的代码转成汇编语言代码，比如 int a = 2; 它会生成mov a, 2;
汇编阶断：把汇编代码转换成机器码，比如把mov a , 2 ; 转成 cd07 (mov指令的机器码中的一种机器码）
链接阶断：制作成一个可执行文件，比如windows是PE的可执行文件,linux是elf的可执行文件，要制作成可以运行的程序。

//预编译(预处理)，为编译做准备工作，完成代码文本的替换工作

头文件告诉编译器有这样一个函数，连接器负责找到这个函数的实现
*/

void method1(){
	//#include "my.txt" //预编译阶段会替换为 printf("%s\n","I am a boy!");
	getchar();
}

/*
define指令 (宏定义、宏替换、预编译指令)
1.定义标识
#ifdef __cplusplus 表示编译器支持C++语法
防止文件重复引入(循环引用，防止A.h引用B.h，同时B.h引用A.h)
2.定义常数 (便于修改和阅读)，会在预编译阶段进行替换
#define MAX 100
3.定义"宏函数"
*/

void method2(){
	//printfA();
	//printfB();
	getchar();
}

//定义常数 
#define MAX 100

void dn_com_jni_read(){
	printf("read\n");
}

void dn_com_jni_write(){
	printf("write\n");
}
//定义"宏函数"
//NAME是参数
#define mytest(NAME) dn_com_jni_##NAME();
//函数名称很长，可用宏函数缩短函数名称

//宏函数实例 -> 日志输出
//__VA_ARGS__可变参数
#define LOG(TAG,...) printf(##TAG,__VA_ARGS__);  //##代表参数 (有时候不加也可以)

void method3(){
	mytest(write);
	getchar();
}

void method4(){
	LOG("%s%d", "大小：", 89);
	getchar();
}

//升级版 日志 (替换两次)
#define LOG(LEVEL,FORMAT,...) printf(##LEVEL); printf(##FORMAT,__VA_ARGS__);
#define LOG_I(FORMAT,...) LOG("INFO:",##FORMAT,__VA_ARGS__);
#define LOG_E(FORMAT,...) LOG("ERROR:",##FORMAT,##__VA_ARGS__);   //##代表参数 (有时候不加也可以)
#define LOG_W(FORMAT,...) LOG("WARN:",##FORMAT,__VA_ARGS__);

void method5(){
	LOG_E("%s%d", "大小：", 90);
	getchar();
}

void main(){
	//method1();
	//method2();
	//method3();
	//method4();
	method5();
}