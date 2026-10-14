// 来源小节：11.x Chapter 11 summary and quiz（复习示例 8）
// 示例说明：非模板 foo(int) 与模板 foo(T) 并存时，五种调用分别选中谁
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
    std::cout << foo(1) << ' '; // 非模板精确匹配 -> 11
    short s { 2 };
    std::cout << foo(s) << ' ';     // 模板 foo<short>(short) 精确匹配优于转换 -> 2
    std::cout << foo<int>(4) << ' '; // 显式模板实参，跳过非模板 -> 4
    std::cout << foo<int>(s) << ' '; // 显式模板实参，short 提升为 int -> 2
    std::cout << foo<>(6) << ' ';    // 空尖括号只考虑模板 -> foo<int>(int) -> 6
    std::cout << '\n';

    return 0;
}
