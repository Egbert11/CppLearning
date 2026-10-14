// 来源小节：O.2 Bitwise operators
// 示例说明：对 4 位 std::bitset 做左移与右移。
// 原文链接：https://www.learncpp.com/cpp-tutorial/bitwise-operators/
//
// 预期输出：
//   1100
//   0110
//   1000
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块）。
#include <bitset>
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::bitset<4> x { 0b1100 };

    std::cout << x << '\n';
    std::cout << (x >> 1) << '\n'; // shift right by 1, yielding 0110
    std::cout << (x << 1) << '\n'; // shift left by 1, yielding 1000
    // --- 原文示例片段结束 ---

    return 0;
}
