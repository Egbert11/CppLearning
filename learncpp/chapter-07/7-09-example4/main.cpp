// 来源小节：7.9 Inline functions and variables
// 示例说明：main.cpp（头文件版）—— 包含 pi.h 获得 pi() 的定义。
// 原文链接：https://www.learncpp.com/cpp-tutorial/inline-functions-and-variables/
//
// 本节示例为按原文描述重建（对应原文 Example 5）。
// 编译：g++ -std=c++20 -Wall 7-09-example4/main.cpp 7-09-example4/math.cpp -o main
// 预期输出：
// 3.14159
// 12.5664

#include "pi.h"

#include <iostream>

double circumference(double radius); // 前向声明

int main()
{
    std::cout << pi() << '\n';
    std::cout << circumference(2.0) << '\n';

    return 0;
}
