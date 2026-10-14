// ============================================================
// 来源小节：16.x Chapter 16 summary and quiz —— 测验 1 解答
// 示例说明：用 CTAD（能用就用）写出 5 种 vector 定义，并输出各自长度以避免未使用变量。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-16-summary-and-quiz/
// 预期输出：6 4 4 1 12
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <string_view>
#include <vector>

int main()
{
    // a) A std::vector with the first 6 even numbers (CTAD deduces std::vector<int>)
    std::vector evens { 2, 4, 6, 8, 10, 12 };

    // b) A constant vector holding 1.2, 3.4, 5.6, 7.8 (std::vector can be const, but not constexpr)
    const std::vector d { 1.2, 3.4, 5.6, 7.8 };

    // c) A constant std::string_view vector of four names: the sv suffix makes CTAD deduce std::string_view
    using namespace std::literals::string_view_literals;
    const std::vector names { "Alex"sv, "Brad"sv, "Chad"sv, "Dave"sv };

    // d) A std::vector with the single value 12 (one element)
    std::vector v { 12 };

    // e) A std::vector of 12 default-initialized ints:
    //    CTAD does NOT work here (there is no initializer to deduce a type from),
    //    so we must name the element type explicitly and use direct initialization.
    std::vector<int> v2(12);

    std::cout << evens.size() << ' ' << d.size() << ' ' << names.size() << ' '
              << v.size() << ' ' << v2.size() << '\n';

    return 0;
}
