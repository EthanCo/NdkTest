#include "Student.h"
#include<iostream>
using namespace std;

//相当于onCreate
/*Student::Student(int i,int j){
	this->i = i;
	this->j = j;
	cout << "构造方法" << endl;
}*/

Student::Student(int i, int j):i(i){ //:i(i) 传参的i会自动赋值
	this->j = j;
	cout << "构造方法" << endl;
}

/*void Student::setJ(int j){
	this->j = j;
}*/

//相当于onDestory
Student::~Student(){
	cout << "析构方法" << endl;
}