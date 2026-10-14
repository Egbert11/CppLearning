// 来源小节：2.12 Header guards
// 示例说明：#pragma once 版本 square.h 的配套定义文件。
// 原文链接：https://www.learncpp.com/cpp-tutorial/header-guards/
//
// 编译：g++ -std=c++20 -Wall 2-12-example3/main.cpp 2-12-example3/square.cpp -o main

#include "square.h"

int getSquareSides()
{
    return 4;
}

int getSquarePerimeter(int sideLength)
{
    return sideLength * getSquareSides();
}
