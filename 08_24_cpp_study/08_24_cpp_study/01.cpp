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

void main(){
	//main1();
	//main2();
	//main3();
	//main4();
	//main5();
	main6();
}