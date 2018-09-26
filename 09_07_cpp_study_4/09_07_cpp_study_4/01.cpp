# include <iostream>

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

void main(){
	//main1();
	//main2();
	//main3();
	main4();
	system("pause");
}