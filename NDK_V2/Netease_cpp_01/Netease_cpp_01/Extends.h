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

	//���麯�� �������Ҫʵ���������
	virtual void test3() = 0;
};

class Parent2{

};

class Child : public Parent, private Parent2 { /*public Parent:���м̳У�private��public����̳�  private Parent:˽�м̳У�ֻ�̳�private��*/
public:
	void test(){
		cout << "Child.test" << endl;
		//Parent::test(); //���ø���ķ���
	}

	//�麯��:��̬��̬
	//���췽�� ��Զ��Ҫ��Ϊ�麯��
	//�������� һ������Ϊ�麯��
	virtual void test2(){
		cout << "Child.test2" << endl;
	}

	virtual ~Child(){

	}

	void test3(){
	}
};