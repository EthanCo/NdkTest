#include <stdlib.h>
//#include <stdio.h> C语言输出方式，C++也可以用，但一般不用
#include <iostream> //标准C++输入输出库 (升级了，.h不需要了)

//命名空间 (类似于Java中的包，解决重名问题)
//标准命名空间(包含很多标准的定义) standard
using namespace std;
//自定义命名空间
namespace NSP_A{
	int a = 9;
}

namespace NSP_B{
	int a = 12;
}

void main(){
	//printf("this is c plus plus"); C语言输出方式，C++也可以用，但一般不用
	//std::cout << "this is c plus plus" << std::endl; //预算法重载， <<就变成了输出的意思
	cout << "this is c plus plus" << endl;
	//使用自定义命名空间
	cout << NSP_A::a << endl;
	cout << NSP_B::a << endl;
	system("pause");
}