#include "Student.h"
#include<iostream>
using namespace std;

//�൱��onCreate
/*Student::Student(int i,int j){
	this->i = i;
	this->j = j;
	cout << "���췽��" << endl;
}*/

Student::Student(int i, int j):i(i){ //:i(i) ���ε�i���Զ���ֵ
	this->j = j;
	cout << "���췽��" << endl;
}

/*void Student::setJ(int j){
	this->j = j;
}*/

//�൱��onDestory
Student::~Student(){
	cout << "��������" << endl;
}