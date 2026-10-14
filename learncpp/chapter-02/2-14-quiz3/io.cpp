// 来源小节：2.x Chapter 2 summary and quiz（官方编号 2.x）
// 题目 3：把前置声明改成用头文件 io.h 提供。
// 示例说明：io.cpp 先 #include "io.h"，再 #include <iostream>，然后定义两个函数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-2-summary-and-quiz/

#include "io.h"
#include <iostream>

int readNumber()
{
    std::cout << "Enter a number to add: ";
    int x {};
    std::cin >> x;

    return x;
}

void writeAnswer(int x)
{
    std::cout << "The answer is " << x << '\n';
}
