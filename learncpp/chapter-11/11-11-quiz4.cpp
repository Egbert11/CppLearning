// 来源小节：11.x Chapter 11 summary and quiz（测验 4）
// 题目：非模板 foo(int) 与模板 foo(T) 的程序输出是什么？
// 解答：11 2 4 2 6。case1 精确匹配非模板；case2 优先精确推导的 foo<short>(short) 而非转 int；
//       case3/case4 显式选 foo<int>（case4 把 short 提升为 int）；case5 的 <> 只匹配模板，故调用 foo<int>(int)。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-11-summary-and-quiz/
// 本节代码为按原文描述重建
// 预期输出：11 2 4 2 6

#include <iostream>

int foo(int n)
{
    return n + 10;
}

template <typename T>
int foo(T n)
{
    return n;
}

int main()
{
    std::cout << foo(1) << ' ';       // 11
    short s { 2 };
    std::cout << foo(s) << ' ';       // 2
    std::cout << foo<int>(4) << ' ';  // 4
    std::cout << foo<int>(s) << ' ';  // 2
    std::cout << foo<>(6) << ' ';     // 6
    std::cout << '\n';

    return 0;
}
