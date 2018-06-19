#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

/*
结构体是一种构造数据类型
把不同的数据类型整合起来成为一个自定义的数据类型
类似于Java中的类
*/

//写法1
struct Man{
	char* name;
	int age;
	char nationality[50];
	int(*func)();
};

void method1(){
	//初始化结构体变量

	//形式1 只能在变量声明时赋值
	//struct Man m1 = { "Jack", 21 };

	//形式2
	struct Man m1;
	m1.age = 25;
	m1.name = "Heiko";
	strcpy(m1.nationality, "China"); //char nationality[50];需要以这种方式赋值
	printf("%s,%d\n", m1.name, m1.age);

	struct Man m2 = m1;

	getchar();
}

//写法2 m3代表一个结构体变量的名称， 全局变量，在整个文件都可以使用
struct Man2{
	char* name;
	int age;
}m3; 

void method2(){
	m3.name = "Hello";
	printf("%s,%d\n", m3.name, m3.age);
	getchar();
}

//写法3 全局变量，在整个文件都可以使用
struct Man3{
	char* name;
	int age;
}m4, m5 = {"jack",20};

//写法4 匿名结构体
//作用: 控制结构体变量的个数 (限量版) ，相当于单例
struct {
	char* name;
	int age;
} m6;

//结构体的嵌套
struct Teacher{
	char* name;
	int age;
};

struct Student{
	char* name;
	int age;
	struct Teacher t;
};

void method3(){
	struct Student s1 = { "jack", 21, { "Jason" ,50} };


	struct Teacher t2;
	t2.name = "Jason2";
	t2.age = 51;
	struct Student s2;
	s2.age = 22;
	s2.name = "jack2";
	s2.t = t2;

	printf("学生s2 %s,%d\n",s2.name,s2.age);
	printf("老师t2 %s,%d\n", s2.t.name, s2.t.age);
	getchar();
}

//结构体和指针
struct Man4{
	char* name;
	int age;
};

void method4(){
	struct Man4 m1 = { "Jack", 30 };
	//结构体指针
	struct Man4 *p = &m1;
	printf("%s,%d\n", m1.name, m1.age);
	printf("%s,%d\n", (*p).name, (*p).age);
	//-> (箭头)是"(*p)."的简写
	printf("%s,%d\n", p->name, p->age);
}

//指针与结构体数组
struct Man5{
	char* name;
	int age;
};

void method5(){
	struct Man5 mans[] = { { "A", 20 }, "B", 19 };
	//遍历数组

	//方式1
	struct Man5 *p = mans;
	for (; p<mans+2; p++)	{
		printf("%s,%d\n", p->name, p->age);
	}

	//方式2
	int i = 0;
	for (; i<sizeof(mans)/sizeof(struct Man5); i++)	{
		printf("%s,%d\n", mans[i].name, mans[i].age);
	}
}

//结构体大小
//结构体变量的大小,必须是最宽基本数据类型的整数倍 (提升读取效率)
//比如以下 int 4字节，double8字节，共12字节，不够，会填充字节，占用16字节
struct Man6{
	int age;
	double weight;
};

void method6(){
	struct Man6 m1 = {20,89.0};
	printf("%#x,%d\n", &m1, sizeof(m1)); //输出结果: 0x6ffd8c,16
	getchar();
}

//结构体和内存分配
void method7(){
	struct Man *m_p = (struct Man*)malloc(sizeof(struct Man) * 10);
	struct Man *p = m_p;
	//赋值
	p->name = "Jack";
	p->age = 20;
	p++;
	p->name = "Rose";
	p->age = 20;
	struct Man *loop_p = m_p;
	for (; loop_p < m_p+2; loop_p++)
	{
		printf("%s,%d\n", loop_p->name, loop_p->age);
	}
	free(m_p);
	getchar();
}

/*
typedef 取别名
1.不同的名称代表在干不同的事情 typedef int jint;
2.不同情况下，取不同的别名
#if defined(__cplusplus)
typedef _JNIEnv JNIEnv;
typedef JavaVM javaVM;
3.书写简洁
typedef int* Ap;  //代表指针
typedef struct Man* M; //代表结构体 用M代表Man*
*/
typedef int Age;
void methodN(){
	Age a = 8;
	getchar();
}

//typedef 给结构体取别名
typedef struct Woman{
	char* name;
	int age;
} W,*WP; //W是woman结构体的别名，WP是woman结构体指针的别名

//等同于
typedef struct Woman W2;
typedef struct Woman* WP2;

void method8(){
	//结构体变量
	W w1 = { "Rose", 20 };
	//结构体指针
	WP wp1 = &w1;

	printf("%s,%d\n", w1.name, w1.age);
	printf("%s,%d\n", wp1->name, wp1->age);
	getchar();
}

//结构体函数指针成员
struct Girl{
	char* name;
	int age;
	//函数指针
	void(*sayHi)(char*);
};

typedef struct Girl* GirlP;

void sayHi(char* text){
	MessageBoxA(0,text,"title",0);
}

void renameGirlName(GirlP gp1){
	gp1->name = "Lily";
}

void method9(){
	struct  Girl g1;
	g1.name = "Lucy";
	g1.age = 18;
	g1.sayHi = sayHi;

	g1.sayHi("hello");

	GirlP gp = &g1;
	renameGirlName(gp);
	gp->sayHi("Good");
	getchar();
}

void main(){
	//method1();
	//method2();
	//method3();
	//method6();
	//method7();
	//method8();
	method9();
}