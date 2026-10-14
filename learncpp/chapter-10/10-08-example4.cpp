// 来源小节：10.8 Type deduction for objects using the auto keyword
// 示例说明：auto 可与 const / constexpr 限定符组合——const auto 得 const int，
//           constexpr auto 得 constexpr int（本身隐含 const）。
//           （对应原文示例 5）
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-for-objects-using-the-auto-keyword/
//
// 编译：g++ -std=c++20 -Wall 10-08-example4.cpp -o a
//
// 本节代码为按原文描述重建。

#include <iostream>
#include <type_traits>

int main()
{
    // --- 原文示例片段 ---
    const auto b{ 5 };     // const int
    constexpr auto c{ 5 }; // constexpr int（隐含 const）
    // --- 原文示例片段结束 ---

    static_assert(std::is_same_v<decltype(b), const int>);
    static_assert(std::is_same_v<decltype(c), const int>); // constexpr 隐含 const

    std::cout << b << ' ' << c << '\n';

    return 0;
}
