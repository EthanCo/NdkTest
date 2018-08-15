#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
//#include <stdio.h> C语言输出方式，C++也可以用，但一般不用
#include <iostream> //标准C++输入输出库 (升级了，.h不需要了)
#include <stdarg.h> //可变参数

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

//引用的主要功能:作为函数的参数或返回值
struct Treacher{
	char* name;
	int age;
};

//引用
void myprint(Treacher &t){
	t.age = 21;
	cout << t.name << "," << t.age << endl;
}

//指针 (稍微要麻烦一些)
void myprint2(Treacher *t){
	t->age = 22;
	//(*t).age = 22; //和t->age相同
	cout << t->name << "," << t->age << endl;
}

void main7(){
	Treacher t;
	t.name = "Jason";
	t.age = 20;
	myprint(t);
	//myprint2(&t);

	system("pause");
}

//二级指针
void getTreacher(Treacher **p){
	Treacher *tem = (Treacher *)malloc(sizeof(Treacher));
	tem->age = 20;
	*p = tem;
}

//指针引用，代替二级指针
void getTreacher2(Treacher* &p){
	p= (Treacher *)malloc(sizeof(Treacher));
	p->age = 20;
}

void main8(){
	Treacher *t = NULL;
	//getTreacher(&t);
	getTreacher2(t);
	system("pause");
}

//指针常量与常量指针
void main9(){
	//指针常量，指针的常量，不改变地址的指针，但可以修改指向的内容
	int a = 2, b = 3;
	int *const p1 = &a;
	//p1 = &b; //指针常量, 无法改变地址
	*p1 = 4; //可以这样改变

	//常量指针，指向常量的指针，内容不能修改
	const int *p2 = &a;
	p2 = &b; //可以这样改变
	//*p2 = 9; //常量指针，无法改变内容
}

//1.单纯给变量取别名没有任何意义，作为函数参数传递，能保证参数传递过程中不产生副本
//2.引用可以直接操作变量，指针要通过取值(*p)，间接操作变量，指针的可读性差

//常引用
void myprintf(const int &a){
	cout << a << endl;
}

void main10(){
	//引用必须要有值，不能为空， 而指针是可以为空的(为了防止报错，指针需要进行非空判断)
	//const int a; 
	//int &a = NULL;

	//常引用
	int a = 10, b = 9;
	const int &c = a;

	//字面量 (常引用的一种写法，用的不多)
	const int &d = 70;

	myprintf(c);

	system("pause");
}
//引用的大小
void main11(){
	Treacher t;
	Treacher &t1 = t;
	Treacher *p = &t;

	cout << sizeof(t1) << endl; //引用是结构体内所有字段大小的综合 char* 4字节，int 4字节，总共8字节
	cout << sizeof(p) << endl; //指针是4
	system("pause");
}

//函数 默认值
void myprint(int x ,int y= 10){
	cout << x <<","<< y << endl;
}

void main12(){
	myprint(1);
	myprint(2,20);
	system("pause");
}

//函数 可变参数 (需要引用 #include <stdarg.h>) 
//单独读取
void func(int i, ...){
	cout << i << endl;
	//可变参数指针
	va_list args_p;
	//开始读取可变参数，i是最后一个固定参数
	va_start(args_p, i);

	int a = va_arg(args_p, int);
	char b = va_arg(args_p, char);
	int c = va_arg(args_p, int);
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	//结束
	va_end(args_p);
}

//函数 可变参数 (需要引用 #include <stdarg.h>) 
//循环读取
void func2(int i, ...){
	cout << i << endl;
	//可变参数指针
	va_list args_p;
	//开始读取可变参数，i是最后一个固定参数
	va_start(args_p, i);

	int value;
	while (1)
	{
		value = va_arg(args_p, int);
		if (value<= 0)
		{
			break;
		}
		cout << value << endl;
	}

	//结束
	va_end(args_p);
}

void main13(){
	func(9, 1, 'b', 3);
	func2(9, 1,2, 3);
	system("pause");
}

//C++ 类 的 普遍写法
//一般把类的声明写在头文件里面，类的实现写在源文件里面
# include "MyTreacher.h"
void main14(){
	MyTreacher t;
	t.setAge(12);
	t.setName("Heiko");
	cout << "name:" << t.getName() << " age:" << t.getAge() << endl;
	system("pause");
}

//构造函数、析构函数、拷贝构造函数
class Teacher2{
private :
	char *name;
	int age;
public:
	//无参构造函数
	Teacher2(){
		cout << "无参构造函数" << endl;
	}
	//有参构造函数
	Teacher2(char *name, int age){
		this->name = name;
		this->age = age;
		cout << "有参构造函数" << endl;
	}
};

class Teacher3{
private:
	char *name;
	int age;
public:
	//赋默认值
	Teacher3(){
		this->name = (char*)malloc(100);
		strcpy(name, "heiko");
		age = 20;
		cout << "---无参构造函数---" << endl;
	}
	//析构函数
	//当对象要被系统释放时，析构函数被调用
	//作用: 善后处理
	~Teacher3(){
		cout << "---析构函数---" << endl;
		//释放内存
		free(this->name);
	}
};

void fun(){
	Teacher3 t3;
}

void main15(){
	Teacher2 t;
	Teacher2 t2("yuehan", 20);
	fun();

	system("pause");
}

//拷贝构造函数
class Teacher4{
private:
	char *name;
	int age;
public:
	//有参构造函数
	Teacher4(char *name, int age){
		strcpy(this->name, name);
		this->age = age;
		cout << "有参构造函数" << endl;
	}
	~Teacher4(){
		cout << "析构" << endl;
		//释放内存
		free(this->name);
	}
	//拷贝构造函数 (浅拷贝，拷贝的是地址)
	//默认拷贝构造函数，就是浅拷贝
	Teacher4(const Teacher4 &obj){
		this->name = obj.name;
		this->age = obj.age;
		cout << "拷贝构造函数" << endl;
	}
	void myprint(){
		cout << name << "," << age << endl;
	}
};

//深拷贝(拷贝的是值，不是地址)
class Teacher5{
private:
	char *name;
	int age;
public:
	//有参构造函数
	Teacher5(char *name, int age){
		int len = strlen(name);
		this->name = (char*)malloc(len + 1); // + 1 结束符
		strcpy(this->name, name);
		this->age = age;
		cout << "有参构造函数" << endl;
	}
	~Teacher5(){
		cout << "析构" << endl;
		//释放内存
		free(this->name);
	}
	//深拷贝
	Teacher5(const Teacher5 &obj){
		//复制name属性
		int len = strlen(obj.name);
		this->name = (char*)malloc(len + 1); // + 1 结束符
		strcpy(this->name, obj.name);
		this->age = obj.age;
		cout << "拷贝构造函数" << endl;
	}
	void myprint(){
		cout << name << "," << age << endl;
	}
};

void main16(){
	Teacher4 t("heiko", 20);
	Teacher4 t2(t);
	t2.myprint();

	//拷贝构造函数 什么时候会被使用
	//1.声明时赋值
	//2.作为参数传入，实参给形参赋值
	//3.作为函数返回值返回，给变量初始化赋值

	system("pause");
}

//构造函数的属性初始化列表
class Teacher17{
private:
	char* name;
public:
	Teacher17(char* name){
		this->name = name;
		cout << "Teacher17有参构造函数" << endl;
	}

	~Teacher17(){
		cout << "Teacher17析构函数" << endl;
	}
	char* getName(){
		return this->name;
	}
};

class Student17{
private:
	int id;
	//属性对象
	//Teacher17 t1;
	//Teacher17 t1 = Teacher17("miss cang");
	Teacher17 t1;
	Teacher17 t2;
public:
	/*Student17(int id){
		this->id = id;
	}*/
	Student17(int id, char* t1_n, char* t2_n) : t1(t1_n), t2(t2_n){ //: t1(t1_n) 给对象赋值
		this->id = id;
		cout << "Student17有参构造函数" << endl;
	}
	~Student17(){
		cout << "Student17析构函数" << endl;
	}
	void myprint(){
		cout << id << "," << t1.getName() << "," << t2.getName()<< endl;
	}
};

void main17(){
	//Student17 s1(10);
	Student17 s1(10, "miss bo", "miss bo2");
	Student17 s2(20, "miss cang", "miss cang2");
	s1.myprint();
	s2.myprint();
}

//动态内存分配
//C++ 通过new(delete) 动态内存分配
//C      malloc(free)

class Teacher18{
private:
	char* name;
public:
	Teacher18(char* name){
		this->name = name;
		cout << "有参构造函数" << endl;
	}

	~Teacher18(){
		cout << "析构函数" << endl;
	}
	char* getName(){
		return this->name;
	}

	void setName(char* name){
		this->name = name;
	}

	//static 静态属性
	static int total;

	//satic 静态函数
	static void count(){
		total++;
	}
};

void main18(){
	//C++
	Teacher18 *t1 = new Teacher18("jack"); //new是动态内存分配，是放在堆内存上面的
	cout << t1->getName() << endl;
	//释放
	delete t1;

	//C
	Teacher18 *t2 = (Teacher18*)malloc(sizeof(Teacher18));
	t2->setName("jack2");
	cout << t2->getName() << endl;
	free(t2);
}

//数组类型
void main19(){
	//C
	int *p1 = (int*)malloc(sizeof(int)* 10);
	p1[0] = 9;
	free(p1);

	//C++
	int *p2 = new int[10];
	p2[0] = 2;
	//释放数组 [] 
	delete[] p2; //free也行，但是不会调用析构函数

	system("pause");
}

//静态属性初始化赋值
int Teacher18::total = 9;

void main20(){
	//Teacher18 t1();
	Teacher18::total++;
	cout << Teacher18::total << endl;

	Teacher18::count();
	//命名空间::Teacher18::count();
	//外部命名空间::内部命名空间::Teacher18::count();
	cout << Teacher18::total << endl;

	//直接通过类名访问
	Teacher18 t1("yuehan");
	t1.count();
	cout << t1.total << endl;
}

//类的大小
class A{
public :
	int i;
	int j;
	int k;
};

class B{
public:
	int i;
	int j;
	int k;
	void myprintf(){
		cout << "打印" << endl;
	}
};

void main21(){
	cout << sizeof(A) << endl; //输出12
	cout << sizeof(B) << endl; //输出12

	//C/C++ 内存分区:栈、堆、全局(静态、全局)、常量区(字符串)、程序代码区
	//普通属性与结构体相同的内存布局

	system("pause");
}

//this是当前对象的指针
//函数是共享的，必须要有能够标识当前对象是谁的方法
class Teacher22{
private:
	char* name;
	int age;
public:
	Teacher22(char* name, int age){
		this->name = name;
		this->age = age;
		cout << "Teacher22有参构造函数" << endl;
	}
	~Teacher22(){
		cout << "Teacher22析构函数" << endl;
	}
	void myprint(){
		printf("%#x\n", this);
		cout << this->name << "," << this->age << endl;
	}

	//常函数，修饰的是this
	//既不能改变指针的值，又不能改变指针指向的内容
	//const 修饰函数，内部this相关的属性都无法被修改
	void mytest() const{
		//this->name = "yuehan";
	}
};

void main22(){
	Teacher22 t1("jack", 20);
	printf("%#x\n", &t1);
	t1.myprint();


	Teacher22 t2("rose", 18);
	printf("%#x\n",&t2);
	t2.myprint();
}

//友元函数
class Class_A{
	//友元类，可以访问Class_A所有的成员
	friend class Class_B;
private:
	int i;
public:
	Class_A(int i){
		this->i = i;
	}
	void myprint(){
		cout << i << endl;
	}

	//友元函数的实现，在友元函数中可以访问私有属性
	friend void modify_i(Class_A*p, int a){
		p->i = a;
	}
};

class Class_B{
public:
	//Class_B这个友元类可以访问Class_A类的任何成员
	void accessAny(){
		a.i = 10;
	}
private:
	Class_A a;
};

void main23(){
	Class_A* a = new Class_A(10);
	a->myprint();

	modify_i(a,20);
	a->myprint();
}

//运算符重载
//本质上还是函数调用
class Point{
private:
	int x;
	int y;
public:
	Point(int x = 0, int y = 0){
		this->x = x;
		this->y = y;
	}

	//成员函数，运算符重载
	Point operator- ( Point &p2){
		Point temp(this->x - p2.x, this->y - p2.y);
		return temp;
	}

	void myprint(){
		cout << x << "," << y << endl;
	}

	int getX(){
		return this->x;
	}

	int getY(){
		return this->y;
	}
};

//重载+号
Point operator+ (Point &p1,Point &p2){
	Point temp(p1.getX() + p2.getX(), p1.getY() + p2.getY());
	return temp;
}

void main24(){
	Point p1(10, 20);
	Point p2(20, 10);
	Point p3 = p1 + p2;

	p3.myprint();

	Point p4 = p1.operator-(p2);
	p4.myprint();

	//Java 中 Str 相加也是运算符重载
	//cout << "" << endl; 也是运算符重载
}

void main(){
	//main1();
	//main2();
	//main3();
	//main4();
	//main5();
	//main6();
	//main7();
	//main8();
	//main9();
	//main10();
	//main11();
	//main12();
	//main13();
	//main14();
	//main15();
	//main16();
	//main17();
	//main18();
	//main19();
	//main20();
	//main21();
	//main22();
	//main23();
	main24();

	system("pause");
}