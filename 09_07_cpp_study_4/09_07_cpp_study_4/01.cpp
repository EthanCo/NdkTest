# include <iostream>

using namespace std;

//C++ ����ת��
//static_cast �ձ����
//const_cast ȥ����
//dynamic_cast ��������תΪ��������
//reinterpret_cast ת������ָ������

//ԭʼ����ת���������������һ��д�����ɶ��Բ��ߣ��п�����Ǳ�ڵķ��ա�
void main1(){
	int i = 0;
	//�Զ�����ת��
	//double d = i;
	double d = 9.5;
	i = d;

	//����ת��
	 i = static_cast < int>(d);

	cout << i << endl;

	system("pause");
}

void func(const char c[]){
	//C�ķ�ʽ
	//ͨ��ָ���Ӹ�ֵ
	//�����˲���֪�������ת����Ϊ��ȥ����
	char* c_p = (char*)c;
	c_p[1] = 'X';

	//C++�ķ�ʽ
	//c_p = static_cast<char*>(c); �޷�ʹ��static_cast������˿ɶ���
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
		cout << "��" << endl;
	}
};

class Man : public Person {
public: 
	void print(){
		cout << "����" << endl;
	}

	void chasing(){
		cout << "���" << endl;
	}
};

class Woman : public Person {
public:
	void print(){
		cout << "Ů��" << endl;
	}

	void careboby(){
		cout << "������" << endl;
	}
};

void func3(Person* obj){
	//obj->print();

	//������������к�����תΪʵ������
	//������֪��ת��ʧ��
	//Man* m = (Man*)obj;
	//m->print();
	//m->chasing();

	//���ת��ʧ�ܣ�����NULL
	Man* m = dynamic_cast<Man*>(obj);
	if (m != NULL){
		m->print();
		m->chasing();
	}
	else{
		cout << "ת��ʧ��" << endl;
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
	//����ָ������
	f_p f_array[6];
	//��ֵ
	f_array[0] = fun4_1;


	//C��д��
	f_array[1] = (f_p)(func4_2);

	//C++��д��
	//f_array[1] = static_cast<f_p>(func4_2); //static_cast ����ת����Ч
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