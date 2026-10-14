// 来源小节：11.x Chapter 11 summary and quiz（复习示例 2）
// 示例说明：带默认实参的 print(int x=0) 与 print() 重载；默认实参不计入重载决议，
//           因而 print() 无法在 print() 与 print(int x=0) 之间取舍。预期编译失败；勿修复。
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
    print(5.0f); // 选择 print(double)（float->double 是提升）
    print();     // compile error: 歧义

    return 0;
}
