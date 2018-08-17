# include <iostream>

//继承
//代码的重用性
using namespace std;

//人类
class Human{
public:
	void say(){
		cout << "说话" << endl;
	}

protected:
	char* name;
	int age;
};

//男人
class Man : public Human{
public:
	//泡妞
	void chsing(){
		cout << "泡妞" << endl;
	}
private:
	//兄弟
	char* brother;
};

void work(Human& m){
	m.say();
}

void main1(){
	Man m1;
	m1.say();

	//1.父类类型的引用或指针
	Human* h_p = &m1;
	h_p->say();

	Human &h1 = m1;
	h1.say();

	work(h1);

	system("pause");
};

//构造方法
//向父类构造方法传参
//人类
class Human2{
public:
	Human2(){}
	Human2(char* name,int age){
		this->name = name;
		this->age = age;
	}
	void say(){
		cout << "说话" << endl;
	}

protected:
	char* name;
	int age;
};

//男人
class Man2 : public Human2{
public:
	Man2(char *brother) : Human2("jack", 20){
		this->brother = brother;
	}
	Man2(char* brother,char *s_name,int s_age):Human2(s_name,s_age){
		this->brother = brother;
	}
	Man2(char* brother, char *s_name, int s_age, char *h_name, int h_age) :Human2(s_name, s_age), h(h_name, h_age){ //h() 给属性对象赋值
		this->brother = brother;
	}
	//泡妞
	void chsing(){
		cout << "泡妞" << endl;
	}
private:
	//兄弟
	char* brother;
	Human2 h;
};

void main2(){
	Man2 m1("danny");
	Man2 m2("danny","jack",18);
	Man2 m3("danny", "jack", 18,"rose",16);
}

//构造函数和析构函数调用的顺序
class Human3{
public:
	Human3(){}
	Human3(char* name, int age){
		this->name = name;
		this->age = age;
		cout << "Human3 构造方法" << endl;
	}
	~Human3(){
		cout << "Human3 析构函数" << endl;
	}
	void say(){
		cout << "说话" << endl;
	}

protected:
	char* name;
	int age;
};


class Man3 : public Human3{
public:
	Man3(char* brother, char *s_name, int s_age) :Human3(s_name, s_age){
		this->brother = brother;
		cout << "Man3 构造方法" << endl;
	}
	~Man3(){
		cout << "Man3 析构函数" << endl;
	}
	//泡妞
	void chsing(){
		cout << "泡妞" << endl;
	}
private:
	//兄弟
	char* brother;
	Human3 h;
};

void main3(){
	//父类构造函数先调用，子类的构造函数再调用
	//子类的析构函数先调用，父类的析构函数再调用
	Man3 m1("danny", "jack", 18);
}

//通过子类对象调用父类的成员
class Human4{
public:
	Human4(){}
	Human4(char* name, int age){
		this->name = name;
		this->age = age;
	}
	void say(){
		cout << "说话" << endl;
	}

public:
	char* name;
	int age;
	char* brother;
};

class Man4 : public Human4{ //public 
public:
	Man4(char *brother, char *s_name, int s_age) : Human4(s_name, s_age){
		this->brother = brother;
	}
	void say(){
		cout << "男人喜欢装逼" << endl;
	}
};

void main4(){
	//是覆盖，并非多态
	Man4 m1("alan", "john", 18);
	m1.say();  //调用子类的say() 男人喜欢装逼
	m1.Human4::say(); //调用父类的say() 说话
	m1.Human4::age = 10; //赋值
}

//多继承
//人
class Person{

};

//公民
class Citizen{

};

//学生，既是人，又是公民
class Student : public Person, public Citizen{
		
};

void main5(){
	
}

/*
继承的修饰符  一般情况下用public继承即可

基类中      继承方式             子类中
public     ＆ public继承        => public
public     ＆ protected继承     => protected
public     ＆ private继承       => private

protected  ＆ public继承        => protected
protected  ＆ protected继承     => protected
protected  ＆ private继承       => private

private    ＆ public继承        => 子类无权访问
private    ＆ protected继承     => 子类无权访问
private    ＆ private继承       => 子类无权访问
*/
class Human6{
public:
	void say(){
		cout << "say" << endl;
	}
protected:
	void say2(){
		cout << "say2" << endl;
	}
private:
	void say3(){
		cout << "say3" << endl;
	}
};

class Man6_1 : public Human6{
	void test(){
		this->say();
		this->say2();
		//this->say3(); //不可访问
	}
};

class Man6_2 : protected Human6{
	void test(){
		this->say();
		this->say2();
		//this->say3(); //不可访问
	}
};

class Man6_3 : private Human6{
	void test(){
		this->say();
		this->say2();
		//this->say3(); //不可访问
	}
};

void main6(){
	Man6_1 man1;
	man1.say();

	Man6_1 man2;
	//man2.say2(); //不可访问

	Man6_2 man3;
	//man3.say(); //不可访问

	Man6_3 man4;
	//man4.say();  //不可访问
}

//继承的二义性
//virtual  虚继承，不同路径继承来的同名成员只有一份拷贝，解决不明确的问题
class A{
public:
	char* name;
};

class A1 : virtual public A{

};

class A2 : virtual public A{

};

class B : public A1, public A2{

};

void main7(){
	B b;
	b.name = "jason";
	//指定父类显示调用
	//b.A1::name = "jason";
	//b.A2::name = "jason";
};

//虚函数
//主要用在多态(程序的扩展性)
//动态多态: 程序运行过程中，决定哪个函数被调用
//静态多态: 重载

//发生多态的条件
//1.基础
//2.父类的引用或者指针指向子类的对象
//3.函数的重写

#include "Plane.h"
#include "Jet.h"
#include "Plane2.h"
#include "Jet2.h"
//业务函数
void bizPlay(Plane& p){
	p.fly();
	p.land();
}

void bizPlay(Plane2& p){
	p.fly();
	p.land();
}

void main8(){
	Plane p1;
	bizPlay(p1); //打印的是 起飞-着陆

	Jet J1;
	bizPlay(J1); //打印的是起飞-着陆

	Plane2 p2;
	bizPlay(p2); //打印的是起飞2-着陆2

	Jet2 J2;
	bizPlay(J2); //打印的是直升飞机起飞2-直升飞机着陆2   // >>>>>虚方法，可多态
}

//纯虚函数
//1.当一个雷具有一个纯虚函数，这个类就是抽象类
//2.抽象类不能实例化对象
//3.子类基础抽象类，必须要实现纯虚函数，如果没有，子类也是抽象类
//抽象类的作用:为了继承约束，根本不知道未来的实现
//形状
class Shape{
public:
	//纯虚函数
	virtual void sayArea() = 0;
};

//圆  >>>> 必须要实现父类的虚函数
class Circle : public Shape{
public:
	Circle(int r){
		this->r = r;
	}
	void sayArea(){ //必须实现
		cout << "圆的面积:" << (3.14*r*2)<<endl;
	}
private:
	int r;
};

void main9(){
	Circle c(10);
}

//接口(只是逻辑上的划分，语法上跟抽象类的写法没有区别)
//可以当做一个接口
class Drawble{
	virtual void draw() = 0;
};

void main10(){
	
}

//模板函数(相当于Java中的泛型)
void myswap(int& a, int& b){
	int tmp = 0;
	tmp = a;
	a = b;
	b = tmp;
}

void myswap(char& a, char& b){
	char tmp = 0;
	tmp = a;
	a = b;
	b = tmp;
}

//发现:上面两个函数业务逻辑一样，数据类型一样，可用下面的模板函数代替
template <typename T>
void myswap2(T& a, T&b){
	T tmp = 0;
	tmp = a;
	a = b;
	b = tmp;
}

void main11(){
	//根据实际类型，自动推倒
	int a = 10, b = 20;
	myswap(a, b);
	cout << a << "," <<b<< endl;
	myswap2(a, b);
	cout << a << ","<<b << endl;
	myswap2<int>(a, b);
	cout << a << "," << b << endl;
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
	main11();
	system("pause");
}