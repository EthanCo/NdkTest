# include <iostream>
#include <fstream> //IO操作

using namespace std;

//C++ 类型转换
//static_cast 普遍情况
//const_cast 去常量
//dynamic_cast 子类类型转为父类类型
//reinterpret_cast 转换函数指针类型

//原始类型转换，所有情况都是一种写法，可读性不高，有可能有潜在的风险。
void main1(){
	int i = 0;
	//自动类型转换
	//double d = i;
	double d = 9.5;
	i = d;

	//类型转换
	 i = static_cast < int>(d);

	cout << i << endl;

	system("pause");
}

void func(const char c[]){
	//C的方式
	//通过指针间接赋值
	//其他人并不知道，这次转型是为了去常量
	char* c_p = (char*)c;
	c_p[1] = 'X';

	//C++的方式
	//c_p = static_cast<char*>(c); 无法使用static_cast，提高了可读性
	c_p = const_cast<char*>(c);
	c_p[1] = 'Y';

	cout << c << endl;
}

void main2(){
	char c[] = "hello";
	func(c);
}

class Person{
public:
	virtual void print(){
		cout << "人" << endl;
	}
};

class Man : public Person {
public: 
	void print(){
		cout << "男人" << endl;
	}

	void chasing(){
		cout << "泡妞" << endl;
	}
};

class Woman : public Person {
public:
	void print(){
		cout << "女人" << endl;
	}

	void careboby(){
		cout << "生孩子" << endl;
	}
};

void func3(Person* obj){
	//obj->print();

	//调用子类的特有函数，转为实际类型
	//并不会知道转型失败
	//Man* m = (Man*)obj;
	//m->print();
	//m->chasing();

	//如果转型失败，返回NULL
	Man* m = dynamic_cast<Man*>(obj);
	if (m != NULL){
		m->print();
		m->chasing();
	}
	else{
		cout << "转型失败" << endl;
	}
}

void main3(){
	Person* person =new Man();
	Person* person2 = new Woman();
	func3(person);
	func3(person2);
}

void fun4_1(){
	cout << "fun4_1" << endl;
}

char* func4_2(){
	cout << "fun4_2" << endl;
	return "abc";
}

typedef void(*f_p)();

void main4(){
	//函数指针数组
	f_p f_array[6];
	//赋值
	f_array[0] = fun4_1;


	//C的写法
	f_array[1] = (f_p)(func4_2);

	//C++的写法
	//f_array[1] = static_cast<f_p>(func4_2); //static_cast 类型转换无效
	f_array[1] = reinterpret_cast<f_p>(func4_2);

	f_array[0]();
	f_array[1]();
}

//IO流
//文本操作流
void main5(){
	char* fname = "D://dest.txt";
	//输出流
	ofstream fout(fname);
	//如果创建失败
	if (fout.bad()){
		return;
	}

	fout << "jack" << endl;
	fout << "rose" << endl;

	//关闭
	fout.close();

	//读取
	ifstream fin(fname);
	if (fin.bad())
	{
		return;
	}
	char ch;
	while (fin.get(ch))
	{
		//输出
		cout << ch;
	}
	fin.close();
}

//二进制文件
void main6(){
	char* src = "D://bg.jpg";
	char* dest = "D://bg2.jpg";

	//输入流
	ifstream fin(src, ios::binary);
	//输出流
	ofstream fout(dest, ios::binary);

	if (fin.bad() || fout.bad())
	{
		return;
	}

	while (!fin.eof()){
		//读取
		char buff[1024] = { 0 };
		fin.read(buff, 1024);

		//写入
		fout.write(buff, 1024);
	}

	fin.close();
	fin.close();
}

//C++ 对象持久化 : 把对象保存到硬盘里面
class Person2
{
public:
	Person2()
	{

	}
	Person2(char * name, int age)
	{
		this->name = name;
		this->age = age;
	}
	void print()
	{
		cout << name << "," << age << endl;
	}
private:
	char * name;
	int age;
};


void main7()
{
	Person2 p1("柳岩", 22);
	Person2 p2("rose", 18);
	//输出流
	ofstream fout("d://c_obj.data", ios::binary);
	fout.write((char*)(&p1), sizeof(Person2)); //指针能够读取到正确的数据，读取内存区的长度
	fout.write((char*)(&p2), sizeof(Person2));
	fout.close();

	//输入流
	ifstream fin("d://c_obj.data", ios::binary);
	Person2 tmp;
	fin.read((char*)(&tmp), sizeof(Person2));
	tmp.print();

	fin.read((char*)(&tmp), sizeof(Person));
	tmp.print();

	system("pause");

}

//stl standard template library 标准模板库   -----------------------------------------------------> 详见 stl.cpp和stl2.cpp (放在了项目最外层)
//util 工具类
//C++集合 操作
//Android Studio 如果要支持，则在新建项目的时候要勾选

#include <string>

void main8(){
	string s1 = "craig david";
	string s2("7 days");
	string s3 = s1 + s2;

	cout << s1 << endl;

	//转C字符串
	const char* c_str = s3.c_str();
	cout << c_str << endl;

	s1.at(2);
	s1.length();
}

//容器 (集合)
#include <vector>

void main9(){
	//动态数组
	//不需要使用动态内存分配，就可以使用动态数组
	vector<int> v;
	v.push_back(12);
	v.push_back(10);
	v.push_back(5);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

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
	main9();
	system("pause");
}