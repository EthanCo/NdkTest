#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

//�ַ����� 
void method1(){
	char a[10] = "Happy";
	//�ַ������鸳ֵ��ֻ��������ʱ
	//a = "";
	//�����޸ĵ�������
	a[0] = "F";
	//���¸�ֵ
	strcpy(a, "Sad");
	getchar();
}

//������(������)
//��ͬ���͵ı�����ͬռ��һ���ڴ�(�໥����)������������κ�ʱ��ֻ��һ����Ա���ڣ���ʡ�ڴ�
//����������Ĵ�С = ���ĳ�Ա��ռ���ֽ���
//����:ͬ��һ������
union MyValue{
	int x;
	int y;
	double z;
};

void method2(){
	union MyValue d1;
	d1.x = 90;
	d1.y = 100;
	//ֻ�����һ�θ�ֵ��Ч����x��y����0��ֻ��z��Ч
	d1.z = 110;

	printf("%d,%d,%lf\n", d1.x, d1.y, d1.z);
	getchar();
}

//ö��
enum Day{
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};

//�൱��
/*
enum Day{
	Monday=0,
	Tuesday=1,
	Wednesday=2,
	Thursday=3,
	Friday=4,
	Saturday=5,
	Sunday=6
};
*/


void method3(){
	enum Day d = Monday;
	printf("%#x,%d\n", &d, d);

	int i = 0;
	enum Day *p = &d;
	for (; i < 7; i++)
	{
		printf("%#x,%d\n", p, *p);
		p++;
	}
	getchar();
}

void main(){
	method2();
	//method3();
}