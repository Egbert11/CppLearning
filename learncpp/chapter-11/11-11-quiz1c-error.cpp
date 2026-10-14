// 来源小节：11.x Chapter 11 summary and quiz（测验 1c）
// 题目：print(long) 与 print(double) 的程序用 print(5) 调用，为何无法编译？
// 解答：字面量 5 是 int；转 long 与转 double 都是转换，没有更优匹配 -> 歧义。
// 预期编译失败；勿修复。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-11-summary-and-quiz/
// 本节代码为按原文描述重建
// 预期错误：call of overloaded 'print(int)' is ambiguous

#include <iostream>

void print(long x)
{
    std::cout << "long " << x << '\n';
}

void print(double x)
{
    std::cout << "double " << x << '\n';
}

int main()
{
    print(5); // compile error: 歧义

    return 0;
}
