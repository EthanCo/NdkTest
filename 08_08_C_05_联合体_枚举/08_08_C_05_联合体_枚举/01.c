#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

//字符数组 
void method1(){
	char a[10] = "Happy";
	//字符串数组赋值，只能在声明时
	//a = "";
	//可以修改单个内容
	a[0] = "F";
	//重新赋值
	strcpy(a, "Sad");
	getchar();
}

//联合体(共用体)
//不同类型的变量共同占用一段内存(相互覆盖)，联合体变量任何时刻只有一个成员存在，节省内存
//联合体变量的大小 = 最大的成员所占的字节数
//比喻:同穿一条裤子
union MyValue{
	int x;
	int y;
	double z;
};

void method2(){
	union MyValue d1;
	d1.x = 90;
	d1.y = 100;
	//只有最后一次赋值有效，即x和y都是0，只有z有效
	d1.z = 110;

	printf("%d,%d,%lf\n", d1.x, d1.y, d1.z);
	getchar();
}

//枚举
enum Day{
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};

//相当于
/*
enum Day{
	Monday=0,
	Tuesday=1,
	Wednesday=2,
	Thursday=3,
	Friday=4,
	Saturday=5,
	Sunday=6
};
*/


void method3(){
	enum Day d = Monday;
	printf("%#x,%d\n", &d, d);

	int i = 0;
	enum Day *p = &d;
	for (; i < 7; i++)
	{
		printf("%#x,%d\n", p, *p);
		p++;
	}
	getchar();
}

void main(){
	method2();
	//method3();
}