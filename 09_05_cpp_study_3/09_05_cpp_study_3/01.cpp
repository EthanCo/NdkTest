#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
//#include <stdio.h> C语言输出方式，C++也可以用，但一般不用
#include <iostream> //标准C++输入输出库 (升级了，.h不需要了)
#include <stdarg.h> //可变参数
#include <stdexcpt> //标准异常

using namespace std;

//C++和Java不一样，C++可以抛出任意的类型，根据抛出的异常数据类型，进入到相应的catch块中
void main1(){
	try{
		int age = 300;
		if (age > 200)
		{
			throw "发生异常";
		}
	}
	catch (int a){
		cout << "int 异常" << endl;
	}
	catch (char* b){
		cout << b << endl;
		cout << "char* 异常" << endl;
	}
	catch (...){
		cout << "未知 异常" << endl;
	}

}

//throw 抛出到函数外面
void mydiv(int a, int b){
	if (b == 0){
		throw "除数为零";
	}
}

void func(){
	try{
		mydiv(8, 0);
	}
	catch (char* a){
		throw a;
	}
}

void main2(){
	/*try{
		mydiv(8, 0);
	}
	catch (char* a){
		cout << a << endl;
	}*/

	try{
		func();
	}
	catch (char* a){
		cout << a << endl;
	}
}

//抛出对象
class MyException{

};

void myThrowObj(){
	throw MyException();
}

void main3(){
	try{
		myThrowObj();
	}
	catch (MyException exception){
		cout << "MyException" << endl;
	}
}

//不要去抛出异常指针，否则要手动释放
void myThrowPointer(){
	throw new MyException; 
}

void main4(){
	try{
		myThrowPointer();
	}
	catch (MyException* exception){
		cout << "MyException指针" << endl;
		delete exception; //需要手动释放
	}
}

//抛出引用
void myThrowQuote(){
	throw MyException();
}

void main5(){
	try{
		myThrowQuote();
	}
	catch (MyException& exception){
		cout << "MyException引用" << endl;
	}
}

//声明抛出异常
void myDeclareThrow() throw (MyException){
	throw MyException();
}

void main6(){
	try{
		myDeclareThrow();
	}
	catch(MyException e){
		cout << "MyException" << endl;
	}
}

//标准异常 (类似于JavaNullPointerException)
void mydiv7( int b){
	if (b > 10){
		throw out_of_range("超出范围");
	}else if (b == 0){
		throw invalid_argument("参数不合法");
	}
}

void main7(){
	try{
		mydiv7(0);
	}
	catch (exception error){
		cout << error.what()<< endl;
	}
}

//自定义异常
class NullPointerException : public exception {
public:
	NullPointerException(char* msg) : exception(msg){
		
	}
};

void mydiv8(){
	throw NullPointerException("为空");
}

void main8(){
	try{
		mydiv8();
	}
	catch (NullPointerException e){
		cout << e.what() << endl;
	}
}

//外部类异常
class Err
{
public:
	class MyException:public exception{
	public:MyException(char* msg):exception(msg){

	}
	};
};

void mydiv9(){
	throw Err::MyException("外部类异常");
}

void main9(){
	try{
		mydiv9();
	}
	catch (Err::MyException e){
		cout << e.what() << endl;
	}
}

//模板类
template<class T>
class A{
public:
	A(T a){
		this->a = a;
	}
protected:
	T a;
};

//普通类继承模板类
class B : public A<int>{
public:
	B(int a,int b):A<int>(a){
		this->b = b;
	}
private:
	int b;
};

//模板类继承模板类
template <class T>
class C : public A<T>{
public:
	C(T c,T a) : A<T>{
		this->c = c;
	}
protected:
	T c;
};

void main10(){
	//实例化模板类对象
	A<int> a(6);
	A<string> b("hello world!");
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
	main10();
	system("pause");
}