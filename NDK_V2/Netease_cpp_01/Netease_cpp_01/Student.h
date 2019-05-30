//防止该头文件被重复引用
#ifndef Student_H

#define Student_H
class Student{
	//友元函数
	friend void studentFriendMethod(Student*);
	//友元类 (友元函数任何东西都可以调用，友元类可以限制调用内容)
	friend class Teacher;
	int i;
public:
	Student(int i,int j);
	~Student(); //析构函数
	void setJ(int j) const; /*加上const就是常量函数，不能修改，不加就可以修改*/
	int getJ(){
		return j;
	}
private:
	int j;
protected:
	int k;
public:
	int l;
};
class Teacher{
public:
	void call(Student* s){
		s->j =10086;
	}
};
#endif
