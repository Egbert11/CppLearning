// 来源小节：11.x Chapter 11 summary and quiz（测验 1b）
// 题目：print()、print(int x=0)、print(double x) 三个重载的程序为何无法编译？
// 解答：带默认值的形参不计入重载决议，print() 无法在 print() 与 print(int x=0) 间取舍。
// 预期编译失败；勿修复。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-11-summary-and-quiz/
// 本节代码为按原文描述重建
// 预期错误：call of overloaded 'print()' is ambiguous

#include <iostream>

void print()
{
    std::cout << "print()\n";
}

void print(int x=0)
{
    std::cout << "print(int)\n";
}

void print(double x)
{
    std::cout << "print(double)\n";
}

int main()
{
    print(5.0f);
    print(); // compile error: 歧义

    return 0;
}
