// 来源小节：2.12 Header guards（课后测验的配套定义文件，用于让示例可编译）
// 原文链接：https://www.learncpp.com/cpp-tutorial/header-guards/
//
// 编译：g++ -std=c++20 -Wall 2-12-example4/main.cpp 2-12-example4/add.cpp -o main

#include "add.h"

int add(int x, int y)
{
    return x + y;
}
