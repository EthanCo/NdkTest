#include <stdlib.h>
//#include <stdio.h> C���������ʽ��C++Ҳ�����ã���һ�㲻��
#include <iostream> //��׼C++��������� (�����ˣ�.h����Ҫ��)

//�����ռ� (������Java�еİ��������������)
//��׼�����ռ�(�����ܶ��׼�Ķ���) standard
using namespace std;
//�Զ��������ռ�
namespace NSP_A{
	int a = 9;
}

namespace NSP_B{
	int a = 12;
}

void main(){
	//printf("this is c plus plus"); C���������ʽ��C++Ҳ�����ã���һ�㲻��
	//std::cout << "this is c plus plus" << std::endl; //Ԥ�㷨���أ� <<�ͱ�����������˼
	cout << "this is c plus plus" << endl;
	//ʹ���Զ��������ռ�
	cout << NSP_A::a << endl;
	cout << NSP_B::a << endl;
	system("pause");
}