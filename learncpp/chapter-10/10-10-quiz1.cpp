// 来源小节：10.x Chapter 10 summary and quiz（本文件编号 10-10）
// 示例说明：测验 1 解答——能通过编译的声明。每行注释标出该情况属于哪类转换。
//           （1c 与 1i 会因窄化而编译失败，已分别放在 10-10-quiz1-c-error.cpp
//             与 10-10-quiz1-i-error.cpp 中单独演示。）
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-10-summary-and-quiz/
//
// 编译：g++ -std=c++20 -Wall 10-10-quiz1.cpp -o a
// 假设：int 与 long 均为 4 字节。
//
// 本节代码为按原文解答要点重建。

#include <iostream>
#include <type_traits>

int main()
{
    int a{ 5 };                        // 1a: 无需转换
    int b{ 'a' };                      // 1b: 数值提升 char -> int
    // int c{ 5.4 };                   // 1c: 无法编译（窄化），见 10-10-quiz1-c-error.cpp
    int d{ true };                     // 1d: 数值提升 bool -> int
    int e{ static_cast<int>(5.4) };    // 1e: 数值转换 double -> int
    double f{ 5.0f };                  // 1f: 数值提升 float -> double
    double g{ 5 };                     // 1g: 数值转换 int -> double
    long h{ 5 };                       // 1h: 数值转换 int -> long（平凡但仍是转换）
    // float i{ f };                   // 1i: 无法编译（窄化），见 10-10-quiz1-i-error.cpp
    float j{ 5.0 };                    // 1j: 数值转换 double -> float（constexpr 且在范围内，允许）

    static_assert(std::is_same_v<decltype(a), int>);
    static_assert(std::is_same_v<decltype(b), int>);
    static_assert(std::is_same_v<decltype(d), int>);
    static_assert(std::is_same_v<decltype(e), int>);
    static_assert(std::is_same_v<decltype(f), double>);
    static_assert(std::is_same_v<decltype(g), double>);
    static_assert(std::is_same_v<decltype(h), long>);
    static_assert(std::is_same_v<decltype(j), float>);

    std::cout << a << ' ' << b << ' ' << d << ' ' << e << '\n';
    std::cout << f << ' ' << g << ' ' << h << ' ' << j << '\n';

    return 0;
}
