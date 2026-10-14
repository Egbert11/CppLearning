// 来源小节：10.8 Type deduction for objects using the auto keyword
// 示例说明：constexpr 与推导的交互——constexpr double a 推导出的 auto b 是 double，
//           const auto c 是 const double，constexpr auto d 也是 const double
//           （constexpr 不缺 const，只是无法从 a 推导出 constexpr 属性）。
//           （对应原文示例 11）
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-for-objects-using-the-auto-keyword/
//
// 编译：g++ -std=c++20 -Wall 10-08-example9.cpp -o a
//
// 本节代码为按原文描述重建。

#include <iostream>
#include <type_traits>

int main()
{
    // --- 原文示例片段 ---
    constexpr double a{ 3.4 };
    auto b{ a };          // double（const 被丢弃）
    const auto c{ a };    // const double
    constexpr auto d{ a }; // const double
    // --- 原文示例片段结束 ---

    static_assert(std::is_same_v<decltype(b), double>);
    static_assert(std::is_same_v<decltype(c), const double>);
    static_assert(std::is_same_v<decltype(d), const double>);

    std::cout << b << ' ' << c << ' ' << d << '\n';

    return 0;
}
