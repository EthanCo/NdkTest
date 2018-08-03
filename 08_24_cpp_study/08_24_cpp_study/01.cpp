#include <stdlib.h>
//#include <stdio.h> C���������ʽ��C++Ҳ�����ã���һ�㲻��
#include <iostream> //��׼C++��������� (�����ˣ�.h����Ҫ��)

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
	//���ñ���Ҫ��ֵ������Ϊ��
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
}