#include <iostream>
using namespace std;

class Parent {
public:
	void test(){
		cout << "Parent.test" << endl;
	}

	void test2(){
		cout << "Child.test2" << endl;
	}

	//纯虚函数 子类必须要实现这个函数
	virtual void test3() = 0;
};

class Parent2{

};

class Child : public Parent, private Parent2 { /*public Parent:公有继承，private和public都会继承  private Parent:私有继承，只继承private的*/
public:
	void test(){
		cout << "Child.test" << endl;
		//Parent::test(); //调用父类的方法
	}

	//虚函数:动态多态
	//构造方法 永远不要设为虚函数
	//析构函数 一般声明为虚函数
	virtual void test2(){
		cout << "Child.test2" << endl;
	}

	virtual ~Child(){

	}

	void test3(){
	}
};