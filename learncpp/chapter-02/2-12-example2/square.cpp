// 来源小节：2.12 Header guards
// 示例说明：square.cpp 存放真正的函数定义，并 #include 与它配对的头文件。
// 原文链接：https://www.learncpp.com/cpp-tutorial/header-guards/
//
// 编译：g++ -std=c++20 -Wall 2-12-example2/main.cpp 2-12-example2/square.cpp -o main

#include "square.h" // square.h is also included once here

int getSquareSides()
{
    return 4;
}

int getSquarePerimeter(int sideLength)
{
    return sideLength * getSquareSides();
}
