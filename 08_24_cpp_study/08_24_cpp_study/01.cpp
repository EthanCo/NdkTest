#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
//#include <stdio.h> C���������ʽ��C++Ҳ�����ã���һ�㲻��
#include <iostream> //��׼C++��������� (�����ˣ�.h����Ҫ��)
#include <stdarg.h> //�ɱ����

//�����ռ� (������Java�еİ��������������)
//��׼�����ռ�(�����ܶ��׼�Ķ���) standard
using namespace std;
//�Զ��������ռ�
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
	//�����ռ�Ƕ��
	namespace NSP_C{
		int c = 90;
	}
}

void main1(){
	//printf("this is c plus plus"); C���������ʽ��C++Ҳ�����ã���һ�㲻��
	//std::cout << "this is c plus plus" << std::endl; //Ԥ�㷨���أ� <<�ͱ�����������˼
	cout << "this is c plus plus" << endl;
	//ʹ���Զ��������ռ�
	cout << NSP_A::a << endl;
	cout << NSP_B::a << endl;
	//ʹ�������ռ�Ƕ��
	cout << NSP_B::NSP_C::c << endl;
	//ʹ�������ռ��еĽṹ��
	/*struct NSP_A::Teacher t;
	t.age = 10;
	struct NSP_A::Student s;*/
	using namespace NSP_A;
	Teacher t;
	t.age = 10;
	Student s;
	system("pause");
}

//�궨��
#define PI  3.14

//Բ
class MyCircle{
	//����(�ɹ���Ȩ�޷������η� private public ��)
private:
	double r;
	double s;
public:
	void setR(double r){
		this->r = r;
	}
	//��ȡ���
	double getS(){
		return PI * r * r;
	}
};

void main2(){
	MyCircle c1;
	c1.setR(4);
	cout << "Բ�����:" << c1.getS() << endl;
	system("pause");
}

/*
C++�нṹ�����������struct��class������

C++�е�struct��C�е�struct���������䣬���Ѿ�����ֻ��һ��������ͬ�������͵����ݽṹ�ˣ����Ѿ���ȡ��̫��Ĺ��ܡ�
struct�ܰ�����Ա������ �ܣ�
struct�ܼ̳��� �ܣ���
struct��ʵ�ֶ�̬�� �ܣ�����
��Ȼ��Щ������ʵ�֣�������class������ʲô����
��ʵ�һ���������Ĭ�ϵķ��ʿ��ƣ�
Ĭ�ϵļ̳з���Ȩ��
struct��public�ģ�class��private�ġ�
*/
struct MyTeacher{
private:
	char name[20];
	int age;

public:
	void say() {
		cout << this->age << "��" << endl;
	}
};

void main3(){
	MyTeacher t1; //struct ��д�ɲ�д
	t1.say();
	system("pause");
}

//��������
void main4(){
	//boolean ����false��0������ֵ��Ϊtrue����˼
	//boolean��һ���ֽڣ���charһ��
	bool isSingle = true;
	//bool isSingle = 17;
	//bool isSingle = -17;
	//bool isSingle = 1;
	//bool isSingle = 0;
	if (isSingle){
		cout << "����" << endl;
	}
	else{
		cout << "�ж���" << endl;
	}
	cout << sizeof(bool) << endl;

	//��Ԫ���ʽ
	int a = 10, b = 20;
	int c = (a > b) ? a : b;
	cout << c<< endl;

	//��ߵĿ��Ը�ֵ�������C��Java�ж�����
	((a > b) ? a:b) = 30;
	cout << b << endl;

	system("pause");
}

//����
void main5(){
	//������-���ƺ�(�ڴ�ռ�0x0001�ı������ɲ������ж������?)
	int a = 10;
	//b�����ڴ�ռ�����һ������
	//���ʾC++�е�����
	int &b = a;
	cout << b << endl;
	system("pause");
}

//ָ��ֵ����
void swap_1(int *a,int *b){
	int c = 0;
	c = *a;
	*a = *b;
	*b= c;
}

//����ֵ����
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

//���õ���Ҫ����:��Ϊ�����Ĳ����򷵻�ֵ
struct Treacher{
	char* name;
	int age;
};

//����
void myprint(Treacher &t){
	t.age = 21;
	cout << t.name << "," << t.age << endl;
}

//ָ�� (��΢Ҫ�鷳һЩ)
void myprint2(Treacher *t){
	t->age = 22;
	//(*t).age = 22; //��t->age��ͬ
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

//����ָ��
void getTreacher(Treacher **p){
	Treacher *tem = (Treacher *)malloc(sizeof(Treacher));
	tem->age = 20;
	*p = tem;
}

//ָ�����ã��������ָ��
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

//ָ�볣���볣��ָ��
void main9(){
	//ָ�볣����ָ��ĳ��������ı��ַ��ָ�룬�������޸�ָ�������
	int a = 2, b = 3;
	int *const p1 = &a;
	//p1 = &b; //ָ�볣��, �޷��ı��ַ
	*p1 = 4; //���������ı�

	//����ָ�룬ָ������ָ�룬���ݲ����޸�
	const int *p2 = &a;
	p2 = &b; //���������ı�
	//*p2 = 9; //����ָ�룬�޷��ı�����
}

//1.����������ȡ����û���κ����壬��Ϊ�����������ݣ��ܱ�֤�������ݹ����в���������
//2.���ÿ���ֱ�Ӳ���������ָ��Ҫͨ��ȡֵ(*p)����Ӳ���������ָ��Ŀɶ��Բ�

//������
void myprintf(const int &a){
	cout << a << endl;
}

void main10(){
	//���ñ���Ҫ��ֵ������Ϊ�գ� ��ָ���ǿ���Ϊ�յ�(Ϊ�˷�ֹ����ָ����Ҫ���зǿ��ж�)
	//const int a; 
	//int &a = NULL;

	//������
	int a = 10, b = 9;
	const int &c = a;

	//������ (�����õ�һ��д�����õĲ���)
	const int &d = 70;

	myprintf(c);

	system("pause");
}
//���õĴ�С
void main11(){
	Treacher t;
	Treacher &t1 = t;
	Treacher *p = &t;

	cout << sizeof(t1) << endl; //�����ǽṹ���������ֶδ�С���ۺ� char* 4�ֽڣ�int 4�ֽڣ��ܹ�8�ֽ�
	cout << sizeof(p) << endl; //ָ����4
	system("pause");
}

//���� Ĭ��ֵ
void myprint(int x ,int y= 10){
	cout << x <<","<< y << endl;
}

void main12(){
	myprint(1);
	myprint(2,20);
	system("pause");
}

//���� �ɱ���� (��Ҫ���� #include <stdarg.h>) 
//������ȡ
void func(int i, ...){
	cout << i << endl;
	//�ɱ����ָ��
	va_list args_p;
	//��ʼ��ȡ�ɱ������i�����һ���̶�����
	va_start(args_p, i);

	int a = va_arg(args_p, int);
	char b = va_arg(args_p, char);
	int c = va_arg(args_p, int);
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	//����
	va_end(args_p);
}

//���� �ɱ���� (��Ҫ���� #include <stdarg.h>) 
//ѭ����ȡ
void func2(int i, ...){
	cout << i << endl;
	//�ɱ����ָ��
	va_list args_p;
	//��ʼ��ȡ�ɱ������i�����һ���̶�����
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

	//����
	va_end(args_p);
}

void main13(){
	func(9, 1, 'b', 3);
	func2(9, 1,2, 3);
	system("pause");
}

//C++ �� �� �ձ�д��
//һ����������д��ͷ�ļ����棬���ʵ��д��Դ�ļ�����
# include "MyTreacher.h"
void main14(){
	MyTreacher t;
	t.setAge(12);
	t.setName("Heiko");
	cout << "name:" << t.getName() << " age:" << t.getAge() << endl;
	system("pause");
}

//���캯���������������������캯��
class Teacher2{
private :
	char *name;
	int age;
public:
	//�޲ι��캯��
	Teacher2(){
		cout << "�޲ι��캯��" << endl;
	}
	//�вι��캯��
	Teacher2(char *name, int age){
		this->name = name;
		this->age = age;
		cout << "�вι��캯��" << endl;
	}
};

class Teacher3{
private:
	char *name;
	int age;
public:
	//��Ĭ��ֵ
	Teacher3(){
		this->name = (char*)malloc(100);
		strcpy(name, "heiko");
		age = 20;
		cout << "---�޲ι��캯��---" << endl;
	}
	//��������
	//������Ҫ��ϵͳ�ͷ�ʱ����������������
	//����: �ƺ���
	~Teacher3(){
		cout << "---��������---" << endl;
		//�ͷ��ڴ�
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

//�������캯��
class Teacher4{
private:
	char *name;
	int age;
public:
	//�вι��캯��
	Teacher4(char *name, int age){
		strcpy(this->name, name);
		this->age = age;
		cout << "�вι��캯��" << endl;
	}
	~Teacher4(){
		cout << "����" << endl;
		//�ͷ��ڴ�
		free(this->name);
	}
	//�������캯�� (ǳ�������������ǵ�ַ)
	//Ĭ�Ͽ������캯��������ǳ����
	Teacher4(const Teacher4 &obj){
		this->name = obj.name;
		this->age = obj.age;
		cout << "�������캯��" << endl;
	}
	void myprint(){
		cout << name << "," << age << endl;
	}
};

//���(��������ֵ�����ǵ�ַ)
class Teacher5{
private:
	char *name;
	int age;
public:
	//�вι��캯��
	Teacher5(char *name, int age){
		int len = strlen(name);
		this->name = (char*)malloc(len + 1); // + 1 ������
		strcpy(this->name, name);
		this->age = age;
		cout << "�вι��캯��" << endl;
	}
	~Teacher5(){
		cout << "����" << endl;
		//�ͷ��ڴ�
		free(this->name);
	}
	//���
	Teacher5(const Teacher5 &obj){
		//����name����
		int len = strlen(obj.name);
		this->name = (char*)malloc(len + 1); // + 1 ������
		strcpy(this->name, obj.name);
		this->age = obj.age;
		cout << "�������캯��" << endl;
	}
	void myprint(){
		cout << name << "," << age << endl;
	}
};

void main16(){
	Teacher4 t("heiko", 20);
	Teacher4 t2(t);
	t2.myprint();

	//�������캯�� ʲôʱ��ᱻʹ��
	//1.����ʱ��ֵ
	//2.��Ϊ�������룬ʵ�θ��βθ�ֵ
	//3.��Ϊ��������ֵ���أ���������ʼ����ֵ

	system("pause");
}

//���캯�������Գ�ʼ���б�
class Teacher17{
private:
	char* name;
public:
	Teacher17(char* name){
		this->name = name;
		cout << "Teacher17�вι��캯��" << endl;
	}

	~Teacher17(){
		cout << "Teacher17��������" << endl;
	}
	char* getName(){
		return this->name;
	}
};

class Student17{
private:
	int id;
	//���Զ���
	//Teacher17 t1;
	//Teacher17 t1 = Teacher17("miss cang");
	Teacher17 t1;
	Teacher17 t2;
public:
	/*Student17(int id){
		this->id = id;
	}*/
	Student17(int id, char* t1_n, char* t2_n) : t1(t1_n), t2(t2_n){ //: t1(t1_n) ������ֵ
		this->id = id;
		cout << "Student17�вι��캯��" << endl;
	}
	~Student17(){
		cout << "Student17��������" << endl;
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

//��̬�ڴ����
//C++ ͨ��new(delete) ��̬�ڴ����
//C      malloc(free)

class Teacher18{
private:
	char* name;
public:
	Teacher18(char* name){
		this->name = name;
		cout << "�вι��캯��" << endl;
	}

	~Teacher18(){
		cout << "��������" << endl;
	}
	char* getName(){
		return this->name;
	}

	void setName(char* name){
		this->name = name;
	}

	//static ��̬����
	static int total;

	//satic ��̬����
	static void count(){
		total++;
	}
};

void main18(){
	//C++
	Teacher18 *t1 = new Teacher18("jack"); //new�Ƕ�̬�ڴ���䣬�Ƿ��ڶ��ڴ������
	cout << t1->getName() << endl;
	//�ͷ�
	delete t1;

	//C
	Teacher18 *t2 = (Teacher18*)malloc(sizeof(Teacher18));
	t2->setName("jack2");
	cout << t2->getName() << endl;
	free(t2);
}

//��������
void main19(){
	//C
	int *p1 = (int*)malloc(sizeof(int)* 10);
	p1[0] = 9;
	free(p1);

	//C++
	int *p2 = new int[10];
	p2[0] = 2;
	//�ͷ����� [] 
	delete[] p2; //freeҲ�У����ǲ��������������

	system("pause");
}

//��̬���Գ�ʼ����ֵ
int Teacher18::total = 9;

void main20(){
	//Teacher18 t1();
	Teacher18::total++;
	cout << Teacher18::total << endl;

	Teacher18::count();
	//�����ռ�::Teacher18::count();
	//�ⲿ�����ռ�::�ڲ������ռ�::Teacher18::count();
	cout << Teacher18::total << endl;

	//ֱ��ͨ����������
	Teacher18 t1("yuehan");
	t1.count();
	cout << t1.total << endl;
}

//��Ĵ�С
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
		cout << "��ӡ" << endl;
	}
};

void main21(){
	cout << sizeof(A) << endl; //���12
	cout << sizeof(B) << endl; //���12

	//C/C++ �ڴ����:ջ���ѡ�ȫ��(��̬��ȫ��)��������(�ַ���)�����������
	//��ͨ������ṹ����ͬ���ڴ沼��

	system("pause");
}

//this�ǵ�ǰ�����ָ��
//�����ǹ���ģ�����Ҫ���ܹ���ʶ��ǰ������˭�ķ���
class Teacher22{
private:
	char* name;
	int age;
public:
	Teacher22(char* name, int age){
		this->name = name;
		this->age = age;
		cout << "Teacher22�вι��캯��" << endl;
	}
	~Teacher22(){
		cout << "Teacher22��������" << endl;
	}
	void myprint(){
		printf("%#x\n", this);
		cout << this->name << "," << this->age << endl;
	}

	//�����������ε���this
	//�Ȳ��ܸı�ָ���ֵ���ֲ��ܸı�ָ��ָ�������
	//const ���κ������ڲ�this��ص����Զ��޷����޸�
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

//��Ԫ����
class Class_A{
	//��Ԫ�࣬���Է���Class_A���еĳ�Ա
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

	//��Ԫ������ʵ�֣�����Ԫ�����п��Է���˽������
	friend void modify_i(Class_A*p, int a){
		p->i = a;
	}
};

class Class_B{
public:
	//Class_B�����Ԫ����Է���Class_A����κγ�Ա
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

//���������
//�����ϻ��Ǻ�������
class Point{
private:
	int x;
	int y;
public:
	Point(int x = 0, int y = 0){
		this->x = x;
		this->y = y;
	}

	//��Ա���������������
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

//����+��
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

	//Java �� Str ���Ҳ�����������
	//cout << "" << endl; Ҳ�����������
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