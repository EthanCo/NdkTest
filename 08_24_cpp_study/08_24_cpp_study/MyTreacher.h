#pragma once //防止重复引用

class MyTreacher{
private:
	int age;
	char* name;

public: //函数的声明
	void setAge(int age);
	int getAge();
	void setName(char* name);
	char* getName();
};