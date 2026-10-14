// 来源小节：7.9 Inline functions and variables
// 示例说明：math.cpp（头文件版）—— 包含 pi.h 获得 pi() 的定义，并定义 circumference()。
// 原文链接：https://www.learncpp.com/cpp-tutorial/inline-functions-and-variables/
//
// 本节示例为按原文描述重建（对应原文 Example 5）。
// 编译：g++ -std=c++20 -Wall 7-09-example4/main.cpp 7-09-example4/math.cpp -o main

#include "pi.h"

double circumference(double radius)
{
    return 2.0 * pi() * radius;
}
