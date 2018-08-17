# include <iostream>

//�̳�
//�����������
using namespace std;

//����
class Human{
public:
	void say(){
		cout << "˵��" << endl;
	}

protected:
	char* name;
	int age;
};

//����
class Man : public Human{
public:
	//���
	void chsing(){
		cout << "���" << endl;
	}
private:
	//�ֵ�
	char* brother;
};

void work(Human& m){
	m.say();
}

void main1(){
	Man m1;
	m1.say();

	//1.�������͵����û�ָ��
	Human* h_p = &m1;
	h_p->say();

	Human &h1 = m1;
	h1.say();

	work(h1);

	system("pause");
};

//���췽��
//���๹�췽������
//����
class Human2{
public:
	Human2(){}
	Human2(char* name,int age){
		this->name = name;
		this->age = age;
	}
	void say(){
		cout << "˵��" << endl;
	}

protected:
	char* name;
	int age;
};

//����
class Man2 : public Human2{
public:
	Man2(char *brother) : Human2("jack", 20){
		this->brother = brother;
	}
	Man2(char* brother,char *s_name,int s_age):Human2(s_name,s_age){
		this->brother = brother;
	}
	Man2(char* brother, char *s_name, int s_age, char *h_name, int h_age) :Human2(s_name, s_age), h(h_name, h_age){ //h() �����Զ���ֵ
		this->brother = brother;
	}
	//���
	void chsing(){
		cout << "���" << endl;
	}
private:
	//�ֵ�
	char* brother;
	Human2 h;
};

void main2(){
	Man2 m1("danny");
	Man2 m2("danny","jack",18);
	Man2 m3("danny", "jack", 18,"rose",16);
}

//���캯���������������õ�˳��
class Human3{
public:
	Human3(){}
	Human3(char* name, int age){
		this->name = name;
		this->age = age;
		cout << "Human3 ���췽��" << endl;
	}
	~Human3(){
		cout << "Human3 ��������" << endl;
	}
	void say(){
		cout << "˵��" << endl;
	}

protected:
	char* name;
	int age;
};


class Man3 : public Human3{
public:
	Man3(char* brother, char *s_name, int s_age) :Human3(s_name, s_age){
		this->brother = brother;
		cout << "Man3 ���췽��" << endl;
	}
	~Man3(){
		cout << "Man3 ��������" << endl;
	}
	//���
	void chsing(){
		cout << "���" << endl;
	}
private:
	//�ֵ�
	char* brother;
	Human3 h;
};

void main3(){
	//���๹�캯���ȵ��ã�����Ĺ��캯���ٵ���
	//��������������ȵ��ã���������������ٵ���
	Man3 m1("danny", "jack", 18);
}

//ͨ�����������ø���ĳ�Ա
class Human4{
public:
	Human4(){}
	Human4(char* name, int age){
		this->name = name;
		this->age = age;
	}
	void say(){
		cout << "˵��" << endl;
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
		cout << "����ϲ��װ��" << endl;
	}
};

void main4(){
	//�Ǹ��ǣ����Ƕ�̬
	Man4 m1("alan", "john", 18);
	m1.say();  //���������say() ����ϲ��װ��
	m1.Human4::say(); //���ø����say() ˵��
	m1.Human4::age = 10; //��ֵ
}

//��̳�
//��
class Person{

};

//����
class Citizen{

};

//ѧ���������ˣ����ǹ���
class Student : public Person, public Citizen{
		
};

void main5(){
	
}

/*
�̳е����η�  һ���������public�̳м���

������      �̳з�ʽ             ������
public     �� public�̳�        => public
public     �� protected�̳�     => protected
public     �� private�̳�       => private

protected  �� public�̳�        => protected
protected  �� protected�̳�     => protected
protected  �� private�̳�       => private

private    �� public�̳�        => ������Ȩ����
private    �� protected�̳�     => ������Ȩ����
private    �� private�̳�       => ������Ȩ����
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
		//this->say3(); //���ɷ���
	}
};

class Man6_2 : protected Human6{
	void test(){
		this->say();
		this->say2();
		//this->say3(); //���ɷ���
	}
};

class Man6_3 : private Human6{
	void test(){
		this->say();
		this->say2();
		//this->say3(); //���ɷ���
	}
};

void main6(){
	Man6_1 man1;
	man1.say();

	Man6_1 man2;
	//man2.say2(); //���ɷ���

	Man6_2 man3;
	//man3.say(); //���ɷ���

	Man6_3 man4;
	//man4.say();  //���ɷ���
}

//�̳еĶ�����
//virtual  ��̳У���ͬ·���̳�����ͬ����Աֻ��һ�ݿ������������ȷ������
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
	//ָ��������ʾ����
	//b.A1::name = "jason";
	//b.A2::name = "jason";
};

//�麯��
//��Ҫ���ڶ�̬(�������չ��)
//��̬��̬: �������й����У������ĸ�����������
//��̬��̬: ����

//������̬������
//1.����
//2.��������û���ָ��ָ������Ķ���
//3.��������д

#include "Plane.h"
#include "Jet.h"
#include "Plane2.h"
#include "Jet2.h"
//ҵ����
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
	bizPlay(p1); //��ӡ���� ���-��½

	Jet J1;
	bizPlay(J1); //��ӡ�������-��½

	Plane2 p2;
	bizPlay(p2); //��ӡ�������2-��½2

	Jet2 J2;
	bizPlay(J2); //��ӡ����ֱ���ɻ����2-ֱ���ɻ���½2   // >>>>>�鷽�����ɶ�̬
}

//���麯��
//1.��һ���׾���һ�����麯�����������ǳ�����
//2.�����಻��ʵ��������
//3.������������࣬����Ҫʵ�ִ��麯�������û�У�����Ҳ�ǳ�����
//�����������:Ϊ�˼̳�Լ����������֪��δ����ʵ��
//��״
class Shape{
public:
	//���麯��
	virtual void sayArea() = 0;
};

//Բ  >>>> ����Ҫʵ�ָ�����麯��
class Circle : public Shape{
public:
	Circle(int r){
		this->r = r;
	}
	void sayArea(){ //����ʵ��
		cout << "Բ�����:" << (3.14*r*2)<<endl;
	}
private:
	int r;
};

void main9(){
	Circle c(10);
}

//�ӿ�(ֻ���߼��ϵĻ��֣��﷨�ϸ��������д��û������)
//���Ե���һ���ӿ�
class Drawble{
	virtual void draw() = 0;
};

void main10(){
	
}

//ģ�庯��(�൱��Java�еķ���)
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

//����:������������ҵ���߼�һ������������һ�������������ģ�庯������
template <typename T>
void myswap2(T& a, T&b){
	T tmp = 0;
	tmp = a;
	a = b;
	b = tmp;
}

void main11(){
	//����ʵ�����ͣ��Զ��Ƶ�
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