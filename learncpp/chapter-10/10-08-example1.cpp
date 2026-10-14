// 来源小节：10.8 Type deduction for objects using the auto keyword
// 示例说明：从字面量、表达式、变量推导类型——auto d{5.0} 得 double，auto i{1+2}
//           得 int，auto x{i} 得 int。用 static_assert 精确校验类型。
//           （对应原文示例 1、2）
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-for-objects-using-the-auto-keyword/
//
// 编译：g++ -std=c++20 -Wall 10-08-example1.cpp -o a
// 预期输出：5 3 3
//
// 本节代码为按原文描述重建。

#include <iostream>
#include <type_traits> // for std::is_same_v

int main()
{
    // --- 原文示例片段（示例 1：显式类型重复了字面量的类型） ---
    double d1{ 5.0 };
    static_assert(std::is_same_v<decltype(d1), double>);
    // --- 原文示例片段结束 ---

    // --- 原文示例片段（示例 2：从字面量、表达式、变量推导） ---
    auto d{ 5.0 };   // 5.0 是 double 字面量，d 推导为 double
    auto i{ 1 + 2 }; // 1 + 2 求值为 int，i 推导为 int
    auto x{ i };     // i 是 int，x 推导为 int
    // --- 原文示例片段结束 ---

    static_assert(std::is_same_v<decltype(d), double>);
    static_assert(std::is_same_v<decltype(i), int>);
    static_assert(std::is_same_v<decltype(x), int>);

    std::cout << d << ' ' << i << ' ' << x << '\n'; // 5 3 3

    return 0;
}
