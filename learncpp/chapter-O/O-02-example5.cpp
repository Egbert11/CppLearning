// 来源小节：O.2 Bitwise operators
// 示例说明：两个位集合的按位或（列中有任意 1 则为 1）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/bitwise-operators/
//
// 预期输出：0111
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块）。
#include <bitset>
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::cout << (std::bitset<4>{ 0b0101 } | std::bitset<4>{ 0b0110 }) << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
