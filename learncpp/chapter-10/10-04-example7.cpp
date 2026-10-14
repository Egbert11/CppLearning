// 来源小节：10.4 Narrowing conversions, list initialization, and constexpr initializers
// 示例说明：constexpr double 到 float 即使丢精度也不算窄化（原文称这一点很奇怪），
//           因此可以合法通过花括号初始化。
// 原文链接：https://www.learncpp.com/cpp-tutorial/narrowing-conversions-list-initialization-and-constexpr-initializers/
//
// 编译：g++ -std=c++20 -Wall 10-04-example7.cpp -o a
//       注：GCC 在 -Wconversion 下仍可能对更窄浮点发出警告（-Wall 不含）。
//
// 本节代码为按原文描述重建。

#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    constexpr double d{ 0.1 };
    float f{ d }; // not narrowing, even though loss of precision results
    // --- 原文示例片段结束 ---

    std::cout << f << '\n';

    return 0;
}
