
//如果没有定义B.h，则定义(老版本的方式)
/*
#ifndef BH
#define BH
#include "B.h"

void printfA();

#endif
*/

//新版本的方式 (该头文件只被包含一次，让编译器自动处理好循环包含问题)
#pragma once
#include "B.h"

void printfA();
