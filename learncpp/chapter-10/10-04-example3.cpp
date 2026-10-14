// 来源小节：10.4 Narrowing conversions, list initialization, and constexpr initializers
// 示例说明：与示例 2 相同的位置，但用 static_cast 显式完成窄化，于是花括号初始化
//           可以通过。
// 原文链接：https://www.learncpp.com/cpp-tutorial/narrowing-conversions-list-initialization-and-constexpr-initializers/
//
// 编译：g++ -std=c++20 -Wall 10-04-example3.cpp -o a
//
// 本节代码为按原文描述重建。

#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    double d{ 3.5 };

    // static_cast<int> converts double to int, initializes i with int result
    int i{ static_cast<int>(d) };
    // --- 原文示例片段结束 ---

    std::cout << i << '\n'; // 3

    return 0;
}
