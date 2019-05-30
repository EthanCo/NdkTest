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

//类
void test1(){
	Student student(10,20);
	//studentFriendMethod(&student);
	Teacher teacher;
	teacher.call(&student);

	//printf();
	//std::cout << "hello world!" << std::endl;
	std::cout << "hello world!\n";
	std::cout << student.getJ() << std::endl; /*std::endl 换行*/
}

//单例
void test2(){
	Person* singleTon = Person::getInstance();
	cout << "单例" << endl;
}

//操作符重载
void test3(){
	Test3 test1;
	test1.i = 100;
	Test3 test2;
	test2.i = 200;
	Test3 test3 = test1 + test2;
	cout << test3.i << endl;
}

//继承、多态、虚函数
void test4(){
	Child child;
	child.test();

	Parent* child2 = new Child();  //静态多态，编译的时候就会确定类型，此处会确认为Parent类型
	child2->test(); //打印的是Parent的test()

	//动态多态 方法名前加 virtual
	Parent* child3 = new Child();
	child3->test2(); //打印的是Child的Test();
}

//函数模板 相当于java中的泛型方法
template <typename T>
T test5(T i, T j){
	return i > j ? i : j;
}

//类模板 相当于java的泛型类
template < class T,class E>
class Q {
public:
	T test(T t, E e){
		return t + e;
	}
};

void throw1(){
	throw "测试1";
}

void throw2(){
	throw exception("测试2");
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

//自定义异常
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

//第一个命名空间
namespace first_space {
	void func(){
		cout << "Inside first_space" << endl;
	}
}

//第二个命名空间
namespace second_space {
	void func(){
		cout << "outsite" << endl;
	}
}

//引用和指针
void test8(){
	int i = 17;
	int* p = &i; //指针
	int& r = i; //引用
	cout << "p:" << *p << endl;
	cout << "r:" << r << endl;
}

void test9(){
	//容器 STL:标准模板库
	//序列式与关联式
	//序列式容器: 元素排列顺序与元素本身无关，由添加顺序决定
	//vector、list、dequeue、queue、stack、priority queue
	vector<int> vec_1;
	//声明一个元素空间
	vector<int> vec_2(1);
	//6个元素 值都是1
	vector<int> vec_3(6, 1);

	vector<int> vec_4(vec_3);
	vec_1.push_back(10);
	//通过下标来获得元素
	cout << "通过下标来获得元素:" << vec_1[0] << endl;
	//直接获得队首与队尾的元素
	vec_1.front();
	vec_1.back();
	vec_1.clear(); //清除容器
	vec_1.erase(vec_1.begin(), vec_1.end()); //清除某一区间的数据

	//关联式容器，根据关键词存储
	//set map hashmap
	set<int> set1 = { 1, 2, 3, 4 };
	set1.insert(1);
	pair < set<int>::iterator, bool> _pair = set1.insert(5);
	std::cout << "set里面有:" << set1.size() << endl;
	set<int>::iterator itt = set1.begin();
	set1.end(); //指向最后一个元素的下一个元素 (null)，用来判断是否遍历到最后了
	for (; itt != set1.end(); itt++){
		cout << *itt << endl;
	}

	//map
	map<int, string> map1;
	map<int, string> map2 = { { 1, "A" }, { 2, "B" } };
	map2.insert({ 3, "C" });
	//修改key为3的元素
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
	cout << q.test(1,1.1) << endl; //打印出2
	test6();
	test7();
	first_space::func(); //调用第一个命名空间的函数
	second_space::func(); //调用第二个命名空间的函数
	test8();
	test9();

	system("pause");
}