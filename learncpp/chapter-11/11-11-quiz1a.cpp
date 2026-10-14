// 来源小节：11.x Chapter 11 summary and quiz（测验 1a）
// 题目：print(int)/print(double) 接收 short s { 5 }，输出什么、为什么？
// 解答：short->int 是提升、short->double 是转换，提升优先，故选 print(int)；输出 int 5。
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
    print(s);

    return 0;
}
