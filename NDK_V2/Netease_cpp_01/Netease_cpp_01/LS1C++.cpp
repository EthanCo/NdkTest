#include<iostream>
#include "Student.h"
#include "Person.h"
#include "Test3.h"
#include "Extends.h"
#include <vector>
#include <set>
#include <map>

using namespace std;
void studentFriendMethod(Student* stu){
	stu->j = 100;
}

//��
void test1(){
	Student student(10,20);
	//studentFriendMethod(&student);
	Teacher teacher;
	teacher.call(&student);

	//printf();
	//std::cout << "hello world!" << std::endl;
	std::cout << "hello world!\n";
	std::cout << student.getJ() << std::endl; /*std::endl ����*/
}

//����
void test2(){
	Person* singleTon = Person::getInstance();
	cout << "����" << endl;
}

//����������
void test3(){
	Test3 test1;
	test1.i = 100;
	Test3 test2;
	test2.i = 200;
	Test3 test3 = test1 + test2;
	cout << test3.i << endl;
}

//�̳С���̬���麯��
void test4(){
	Child child;
	child.test();

	Parent* child2 = new Child();  //��̬��̬�������ʱ��ͻ�ȷ�����ͣ��˴���ȷ��ΪParent����
	child2->test(); //��ӡ����Parent��test()

	//��̬��̬ ������ǰ�� virtual
	Parent* child3 = new Child();
	child3->test2(); //��ӡ����Child��Test();
}

//����ģ�� �൱��java�еķ��ͷ���
template <typename T>
T test5(T i, T j){
	return i > j ? i : j;
}

//��ģ�� �൱��java�ķ�����
template < class T,class E>
class Q {
public:
	T test(T t, E e){
		return t + e;
	}
};

void throw1(){
	throw "����1";
}

void throw2(){
	throw exception("����2");
}

void test6(){
	try{
		throw1();
	}catch (const char *m){
		cout << "test6:"<< m << endl;
	}

	try{
		throw2();
	}catch (exception &e){
		cout << "test6.2:" << e.what() << endl;
	}
}

//�Զ����쳣
class MyException : public exception{
public:
	virtual char const* what() const {
		return "myexception";
	}
};

void throw3(){
	throw MyException();
}

void test7(){
	try{
		throw3();
	}catch (MyException &e){
		cout << e.what() << endl;
	}
}

//��һ�������ռ�
namespace first_space {
	void func(){
		cout << "Inside first_space" << endl;
	}
}

//�ڶ��������ռ�
namespace second_space {
	void func(){
		cout << "outsite" << endl;
	}
}

//���ú�ָ��
void test8(){
	int i = 17;
	int* p = &i; //ָ��
	int& r = i; //����
	cout << "p:" << *p << endl;
	cout << "r:" << r << endl;
}

void test9(){
	//���� STL:��׼ģ���
	//����ʽ�����ʽ
	//����ʽ����: Ԫ������˳����Ԫ�ر����޹أ������˳�����
	//vector��list��dequeue��queue��stack��priority queue
	vector<int> vec_1;
	//����һ��Ԫ�ؿռ�
	vector<int> vec_2(1);
	//6��Ԫ�� ֵ����1
	vector<int> vec_3(6, 1);

	vector<int> vec_4(vec_3);
	vec_1.push_back(10);
	//ͨ���±������Ԫ��
	cout << "ͨ���±������Ԫ��:" << vec_1[0] << endl;
	//ֱ�ӻ�ö������β��Ԫ��
	vec_1.front();
	vec_1.back();
	vec_1.clear(); //�������
	vec_1.erase(vec_1.begin(), vec_1.end()); //���ĳһ���������

	//����ʽ���������ݹؼ��ʴ洢
	//set map hashmap
	set<int> set1 = { 1, 2, 3, 4 };
	set1.insert(1);
	pair < set<int>::iterator, bool> _pair = set1.insert(5);
	std::cout << "set������:" << set1.size() << endl;
	set<int>::iterator itt = set1.begin();
	set1.end(); //ָ�����һ��Ԫ�ص���һ��Ԫ�� (null)�������ж��Ƿ�����������
	for (; itt != set1.end(); itt++){
		cout << *itt << endl;
	}

	//map
	map<int, string> map1;
	map<int, string> map2 = { { 1, "A" }, { 2, "B" } };
	map2.insert({ 3, "C" });
	//�޸�keyΪ3��Ԫ��
	map2[3] = "D";
}

int main(){
	test1();
	test2();
	test3();
	test4();
	double f = test5(13.2, 15.3);
	cout << f << endl;
	Q<int, float> q;
	cout << q.test(1,1.1) << endl; //��ӡ��2
	test6();
	test7();
	first_space::func(); //���õ�һ�������ռ�ĺ���
	second_space::func(); //���õڶ��������ռ�ĺ���
	test8();
	test9();

	system("pause");
}