// ============================================================
// 来源小节：12.x Chapter 12 summary and quiz（本章第 16 个、即总结小节）
// 示例说明：测验第 1 题的五个表达式，分别判断是左值还是右值。
//   (a) 5        —— 字面量，右值
//   (b) x        —— 命名变量，左值
//   (c) x + 1    —— 计算出的临时值，右值
//   (d) foo()    —— 按值返回，右值
//   (e) max(x,y) —— 返回左值引用，左值
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-12-summary-and-quiz/
// 备注：测验 1 的答案本质上是概念性的；这里把五个表达式写成可编译程序并
//       打印结果，分类见上方注释。
// ============================================================
#include <iostream>

int foo()
{
    return 5;
}

int& max(int& x, int& y)
{
    return x > y ? x : y;
}

int main()
{
    std::cout << 5 << '\n'; // (a) 5 is an rvalue

    int x { 5 };
    std::cout << x << '\n'; // (b) x is an lvalue

    std::cout << x + 1 << '\n'; // (c) x + 1 is an rvalue (a temporary)

    std::cout << foo() << '\n'; // (d) foo() returns by value, so it is an rvalue

    int y { 6 };
    std::cout << max(x, y) << '\n'; // (e) max() returns an lvalue reference, so it is an lvalue

    return 0;
}
