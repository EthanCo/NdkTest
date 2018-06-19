
//如果没有定义A.h，则定义 (老版本的方式)
/*
#ifndef AH
#define AH
#include "A.h"

void printfB();

#endif
*/


//新版本的方式 (该头文件只被包含一次，让编译器自动处理好循环包含问题)
#pragma once
#include "A.h"

void printfB();