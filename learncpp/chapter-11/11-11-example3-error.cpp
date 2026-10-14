// 来源小节：11.x Chapter 11 summary and quiz（复习示例 3）
// 示例说明：print(long) 与 print(double) 被 int 字面量 5 调用；
//           int->long 与 int->double 都是转换，没有更优者，歧义。预期编译失败；勿修复。
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
    print(5); // 5 是 int；int->long 与 int->double 都是转换 -> 歧义

    return 0;
}
