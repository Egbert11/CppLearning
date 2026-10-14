// 来源小节：O.2 Bitwise operators
// 示例说明：两个位集合的按位异或（两位不同时结果该位为 1）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/bitwise-operators/
//
// 预期输出：0100
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块）。
#include <bitset>
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::cout << (std::bitset<4>{ 0b0111 } ^ std::bitset<4>{ 0b0011 }) << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
