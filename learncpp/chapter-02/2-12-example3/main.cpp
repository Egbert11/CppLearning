// 来源小节：2.12 Header guards
// 示例说明：#pragma once 版本示例的调用方。预期输出：
//           a square has 4 sides
//           a square of length 5 has perimeter length 20
// 原文链接：https://www.learncpp.com/cpp-tutorial/header-guards/
//
// 编译：g++ -std=c++20 -Wall 2-12-example3/main.cpp 2-12-example3/square.cpp -o main

#include "square.h"
#include <iostream>

int main()
{
    std::cout << "a square has " << getSquareSides() << " sides\n";
    std::cout << "a square of length 5 has perimeter length " << getSquarePerimeter(5) << '\n';

    return 0;
}
