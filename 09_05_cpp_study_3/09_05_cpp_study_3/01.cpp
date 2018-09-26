#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
//#include <stdio.h> C���������ʽ��C++Ҳ�����ã���һ�㲻��
#include <iostream> //��׼C++��������� (�����ˣ�.h����Ҫ��)
#include <stdarg.h> //�ɱ����
#include <stdexcpt> //��׼�쳣

using namespace std;

//C++��Java��һ����C++�����׳���������ͣ������׳����쳣�������ͣ����뵽��Ӧ��catch����
void main1(){
	try{
		int age = 300;
		if (age > 200)
		{
			throw "�����쳣";
		}
	}
	catch (int a){
		cout << "int �쳣" << endl;
	}
	catch (char* b){
		cout << b << endl;
		cout << "char* �쳣" << endl;
	}
	catch (...){
		cout << "δ֪ �쳣" << endl;
	}

}

//throw �׳�����������
void mydiv(int a, int b){
	if (b == 0){
		throw "����Ϊ��";
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

//�׳�����
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

//��Ҫȥ�׳��쳣ָ�룬����Ҫ�ֶ��ͷ�
void myThrowPointer(){
	throw new MyException; 
}

void main4(){
	try{
		myThrowPointer();
	}
	catch (MyException* exception){
		cout << "MyExceptionָ��" << endl;
		delete exception; //��Ҫ�ֶ��ͷ�
	}
}

//�׳�����
void myThrowQuote(){
	throw MyException();
}

void main5(){
	try{
		myThrowQuote();
	}
	catch (MyException& exception){
		cout << "MyException����" << endl;
	}
}

//�����׳��쳣
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

//��׼�쳣 (������JavaNullPointerException)
void mydiv7( int b){
	if (b > 10){
		throw out_of_range("������Χ");
	}else if (b == 0){
		throw invalid_argument("�������Ϸ�");
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

//�Զ����쳣
class NullPointerException : public exception {
public:
	NullPointerException(char* msg) : exception(msg){
		
	}
};

void mydiv8(){
	throw NullPointerException("Ϊ��");
}

void main8(){
	try{
		mydiv8();
	}
	catch (NullPointerException e){
		cout << e.what() << endl;
	}
}

//�ⲿ���쳣
class Err
{
public:
	class MyException:public exception{
	public:MyException(char* msg):exception(msg){

	}
	};
};

void mydiv9(){
	throw Err::MyException("�ⲿ���쳣");
}

void main9(){
	try{
		mydiv9();
	}
	catch (Err::MyException e){
		cout << e.what() << endl;
	}
}

//ģ����
template<class T>
class A{
public:
	A(T a){
		this->a = a;
	}
protected:
	T a;
};

//��ͨ��̳�ģ����
class B : public A<int>{
public:
	B(int a,int b):A<int>(a){
		this->b = b;
	}
private:
	int b;
};

//ģ����̳�ģ����
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
	//ʵ����ģ�������
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