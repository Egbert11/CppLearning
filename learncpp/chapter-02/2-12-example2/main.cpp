// 来源小节：2.12 Header guards
// 示例说明：调用方保持不变。因为定义只出现一次，现在可以正常编译链接。
//           预期输出：
//           a square has 4 sides
//           a square of length 5 has perimeter length 20
// 原文链接：https://www.learncpp.com/cpp-tutorial/header-guards/
//
// 编译：g++ -std=c++20 -Wall 2-12-example2/main.cpp 2-12-example2/square.cpp -o main

#include "square.h"
#include <iostream>

int main()
{
    std::cout << "a square has " << getSquareSides() << " sides\n";
    std::cout << "a square of length 5 has perimeter length " << getSquarePerimeter(5) << '\n';

    return 0;
}
