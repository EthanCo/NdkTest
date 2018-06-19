#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

/*
�ṹ����һ�ֹ�����������
�Ѳ�ͬ��������������������Ϊһ���Զ������������
������Java�е���
*/

//д��1
struct Man{
	char* name;
	int age;
	char nationality[50];
	int(*func)();
};

void method1(){
	//��ʼ���ṹ�����

	//��ʽ1 ֻ���ڱ�������ʱ��ֵ
	//struct Man m1 = { "Jack", 21 };

	//��ʽ2
	struct Man m1;
	m1.age = 25;
	m1.name = "Heiko";
	strcpy(m1.nationality, "China"); //char nationality[50];��Ҫ�����ַ�ʽ��ֵ
	printf("%s,%d\n", m1.name, m1.age);

	struct Man m2 = m1;

	getchar();
}

//д��2 m3����һ���ṹ����������ƣ� ȫ�ֱ������������ļ�������ʹ��
struct Man2{
	char* name;
	int age;
}m3; 

void method2(){
	m3.name = "Hello";
	printf("%s,%d\n", m3.name, m3.age);
	getchar();
}

//д��3 ȫ�ֱ������������ļ�������ʹ��
struct Man3{
	char* name;
	int age;
}m4, m5 = {"jack",20};

//д��4 �����ṹ��
//����: ���ƽṹ������ĸ��� (������) ���൱�ڵ���
struct {
	char* name;
	int age;
} m6;

//�ṹ���Ƕ��
struct Teacher{
	char* name;
	int age;
};

struct Student{
	char* name;
	int age;
	struct Teacher t;
};

void method3(){
	struct Student s1 = { "jack", 21, { "Jason" ,50} };


	struct Teacher t2;
	t2.name = "Jason2";
	t2.age = 51;
	struct Student s2;
	s2.age = 22;
	s2.name = "jack2";
	s2.t = t2;

	printf("ѧ��s2 %s,%d\n",s2.name,s2.age);
	printf("��ʦt2 %s,%d\n", s2.t.name, s2.t.age);
	getchar();
}

//�ṹ���ָ��
struct Man4{
	char* name;
	int age;
};

void method4(){
	struct Man4 m1 = { "Jack", 30 };
	//�ṹ��ָ��
	struct Man4 *p = &m1;
	printf("%s,%d\n", m1.name, m1.age);
	printf("%s,%d\n", (*p).name, (*p).age);
	//-> (��ͷ)��"(*p)."�ļ�д
	printf("%s,%d\n", p->name, p->age);
}

//ָ����ṹ������
struct Man5{
	char* name;
	int age;
};

void method5(){
	struct Man5 mans[] = { { "A", 20 }, "B", 19 };
	//��������

	//��ʽ1
	struct Man5 *p = mans;
	for (; p<mans+2; p++)	{
		printf("%s,%d\n", p->name, p->age);
	}

	//��ʽ2
	int i = 0;
	for (; i<sizeof(mans)/sizeof(struct Man5); i++)	{
		printf("%s,%d\n", mans[i].name, mans[i].age);
	}
}

//�ṹ���С
//�ṹ������Ĵ�С,�������������������͵������� (������ȡЧ��)
//�������� int 4�ֽڣ�double8�ֽڣ���12�ֽڣ�������������ֽڣ�ռ��16�ֽ�
struct Man6{
	int age;
	double weight;
};

void method6(){
	struct Man6 m1 = {20,89.0};
	printf("%#x,%d\n", &m1, sizeof(m1)); //������: 0x6ffd8c,16
	getchar();
}

//�ṹ����ڴ����
void method7(){
	struct Man *m_p = (struct Man*)malloc(sizeof(struct Man) * 10);
	struct Man *p = m_p;
	//��ֵ
	p->name = "Jack";
	p->age = 20;
	p++;
	p->name = "Rose";
	p->age = 20;
	struct Man *loop_p = m_p;
	for (; loop_p < m_p+2; loop_p++)
	{
		printf("%s,%d\n", loop_p->name, loop_p->age);
	}
	free(m_p);
	getchar();
}

/*
typedef ȡ����
1.��ͬ�����ƴ����ڸɲ�ͬ������ typedef int jint;
2.��ͬ����£�ȡ��ͬ�ı���
#if defined(__cplusplus)
typedef _JNIEnv JNIEnv;
typedef JavaVM javaVM;
3.��д���
typedef int* Ap;  //����ָ��
typedef struct Man* M; //����ṹ�� ��M����Man*
*/
typedef int Age;
void methodN(){
	Age a = 8;
	getchar();
}

//typedef ���ṹ��ȡ����
typedef struct Woman{
	char* name;
	int age;
} W,*WP; //W��woman�ṹ��ı�����WP��woman�ṹ��ָ��ı���

//��ͬ��
typedef struct Woman W2;
typedef struct Woman* WP2;

void method8(){
	//�ṹ�����
	W w1 = { "Rose", 20 };
	//�ṹ��ָ��
	WP wp1 = &w1;

	printf("%s,%d\n", w1.name, w1.age);
	printf("%s,%d\n", wp1->name, wp1->age);
	getchar();
}

//�ṹ�庯��ָ���Ա
struct Girl{
	char* name;
	int age;
	//����ָ��
	void(*sayHi)(char*);
};

typedef struct Girl* GirlP;

void sayHi(char* text){
	MessageBoxA(0,text,"title",0);
}

void renameGirlName(GirlP gp1){
	gp1->name = "Lily";
}

void method9(){
	struct  Girl g1;
	g1.name = "Lucy";
	g1.age = 18;
	g1.sayHi = sayHi;

	g1.sayHi("hello");

	GirlP gp = &g1;
	renameGirlName(gp);
	gp->sayHi("Good");
	getchar();
}

void main(){
	//method1();
	//method2();
	//method3();
	//method6();
	//method7();
	//method8();
	method9();
}