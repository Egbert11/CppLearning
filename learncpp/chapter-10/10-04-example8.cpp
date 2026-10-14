// 来源小节：10.4 Narrowing conversions, list initialization, and constexpr initializers
// 示例说明：借助 constexpr 初始化，可以直接用 int/double 字面量与 constexpr 对象去
//           列表初始化其他类型，无需字面量后缀，也无需 static_cast。
// 原文链接：https://www.learncpp.com/cpp-tutorial/narrowing-conversions-list-initialization-and-constexpr-initializers/
//
// 编译：g++ -std=c++20 -Wall 10-04-example8.cpp -o a
//
// 本节代码为按原文描述重建。

#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    // We can avoid literals with suffixes
    unsigned int u{ 5 }; // okay (we don't need to use `5u`)
    float f{ 1.5 };      // okay (we don't need to use `1.5f`)

    // We can avoid static_casts
    constexpr int n{ 5 };
    double d{ n };       // okay (we don't need a static_cast here)
    short s{ 5 };        // okay (there is no suffix for short, we don't need a static_cast here)
    // --- 原文示例片段结束 ---

    std::cout << u << ' ' << f << ' ' << d << ' ' << s << '\n';

    return 0;
}
