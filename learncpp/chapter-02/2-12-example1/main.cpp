// 来源小节：2.12 Header guards
// 示例说明：main.cpp 同时包含 square.h 与 wave.h。由于二者都有 header guard，
//           预处理后 getSquareSides() 的定义在本翻译单元中只出现一次，程序可以正常编译。
// 原文链接：https://www.learncpp.com/cpp-tutorial/header-guards/
//
// 编译：g++ -std=c++20 -Wall 2-12-example1/main.cpp -o main

#include "square.h"
#include "wave.h"

int main()
{
    return 0;
}
