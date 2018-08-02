#include <stdlib.h>
//#include <stdio.h> C语言输出方式，C++也可以用，但一般不用
#include <iostream> //标准C++输入输出库 (升级了，.h不需要了)

//命名空间 (类似于Java中的包，解决重名问题)
//标准命名空间(包含很多标准的定义) standard
using namespace std;
//自定义命名空间
namespace NSP_A{
	int a = 9;
	struct Teacher{
		char name[20];
		int age;
	};
	struct Student{
		char name[20];
		int age;
	};
}

namespace NSP_B{
	int a = 12;
	//命名空间嵌套
	namespace NSP_C{
		int c = 90;
	}
}

void main1(){
	//printf("this is c plus plus"); C语言输出方式，C++也可以用，但一般不用
	//std::cout << "this is c plus plus" << std::endl; //预算法重载， <<就变成了输出的意思
	cout << "this is c plus plus" << endl;
	//使用自定义命名空间
	cout << NSP_A::a << endl;
	cout << NSP_B::a << endl;
	//使用命名空间嵌套
	cout << NSP_B::NSP_C::c << endl;
	//使用命名空间中的结构体
	/*struct NSP_A::Teacher t;
	t.age = 10;
	struct NSP_A::Student s;*/
	using namespace NSP_A;
	Teacher t;
	t.age = 10;
	Student s;
	system("pause");
}

//宏定义
#define PI  3.14

//圆
class MyCircle{
	//属性(可共用权限访问修饰符 private public 等)
private:
	double r;
	double s;
public:
	void setR(double r){
		this->r = r;
	}
	//获取面积
	double getS(){
		return PI * r * r;
	}
};

void main2(){
	MyCircle c1;
	c1.setR(4);
	cout << "圆的面积:" << c1.getS() << endl;
	system("pause");
}

/*
C++中结构体与类的区别（struct与class的区别）

C++中的struct对C中的struct进行了扩充，它已经不再只是一个包含不同数据类型的数据结构了，它已经获取了太多的功能。
struct能包含成员函数吗？ 能！
struct能继承吗？ 能！！
struct能实现多态吗？ 能！！！
既然这些它都能实现，那它和class还能有什么区别？
最本质的一个区别就是默认的访问控制：
默认的继承访问权限
struct是public的，class是private的。
*/
struct MyTeacher{
private:
	char name[20];
	int age;

public:
	void say() {
		cout << this->age << "岁" << endl;
	}
};

void main3(){
	MyTeacher t1; //struct 可写可不写
	t1.say();
	system("pause");
}

//布尔类型
void main4(){
	//boolean 除了false和0，其他值都为true的意思
	//boolean是一个字节，和char一样
	bool isSingle = true;
	//bool isSingle = 17;
	//bool isSingle = -17;
	//bool isSingle = 1;
	//bool isSingle = 0;
	if (isSingle){
		cout << "单身" << endl;
	}
	else{
		cout << "有对象" << endl;
	}
	cout << sizeof(bool) << endl;

	//三元表达式
	int a = 10, b = 20;
	int c = (a > b) ? a : b;
	cout << c<< endl;

	//左边的可以赋值，这个在C和Java中都不行
	((a > b) ? a:b) = 30;
	cout << b << endl;

	system("pause");
}

//引用
void main5(){
	//变量名-门牌号(内存空间0x0001的别名，可不可以有多个名字?)
	int a = 10;
	//b就是内存空间另外一个别名
	//这表示C++中的引用
	int &b = a;
	cout << b << endl;
	system("pause");
}

//指针值交换
void swap_1(int *a,int *b){
	int c = 0;
	c = *a;
	*a = *b;
	*b= c;
}

//引用值交换
void swap_2(int &a,int &b){
	int c = 0;
	c = a;
	a = b;
	b = c;
}

void main6(){
	int x = 10;
	int y = 20;

	printf("%d,%d\n", x, y);
	//swap_1(&x,&y);
	swap_2(x, y);
	printf("%d,%d\n", x, y);
	system("pause");
}

void main(){
	//main1();
	//main2();
	//main3();
	//main4();
	//main5();
	main6();
}