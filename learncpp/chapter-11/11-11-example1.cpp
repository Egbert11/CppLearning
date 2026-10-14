// 来源小节：11.x Chapter 11 summary and quiz（复习示例 1）
// 示例说明：重载 print(int) 与 print(double)；short 实参经整型提升选 print(int)
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-11-summary-and-quiz/
// 本节代码为按原文描述重建
// 预期输出：int 5

#include <iostream>

void print(int x)
{
    std::cout << "int " << x << '\n';
}

void print(double x)
{
    std::cout << "double " << x << '\n';
}

int main()
{
    short s { 5 };
    print(s); // short->int 是提升，short->double 是转换，提升优先 -> print(int)

    return 0;
}
