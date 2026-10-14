// 来源小节：10.3 Numeric conversions
// 示例说明：符号/无符号的重解释（reinterpretive）转换及往返。5 转换后仍是 5；
//           -5 转换成无符号后变成一个超出有符号范围的大值，但再转回 int 能复现 -5。
//           （对应原文示例 8、9）
// 原文链接：https://www.learncpp.com/cpp-tutorial/numeric-conversions/
// 预期警告：本示例演示的正是会产生该警告的写法（-warning 后缀），警告为预期行为，请勿消除。
//
// 编译：g++ -std=c++20 -Wall 10-03-example3.cpp -o a
// 预期输出：
//   5 4294967291
//   -5
//
// 本节代码为按原文描述重建。

#include <iostream>

int main()
{
    // --- 原文示例片段（符号 -> 无符号） ---
    int n1{ 5 };
    unsigned int u1{ n1 }; // okay: will be converted to unsigned int 5 (value preserved)

    int n2{ -5 };
    unsigned int u2{ n2 }; // bad: will result in large integer outside range of signed int
    // --- 原文示例片段结束 ---

    std::cout << u1 << ' ' << u2 << '\n'; // 5 4294967291

    // --- 原文示例片段（重解释往返） ---
    int u = static_cast<int>(static_cast<unsigned int>(-5)); // convert '-5' to unsigned and back
    // --- 原文示例片段结束 ---

    std::cout << u << '\n'; // -5

    return 0;
}
