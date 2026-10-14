// 来源小节：O.2 Bitwise operators
// 示例说明：展示位宽如何影响按位取反 ~ 的结果（前导 1 位会贡献数值）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/bitwise-operators/
//
// 预期输出：
//   0100 00000100
//   4 4
//   1011 11111011
//   11 251
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块）。
#include <bitset>
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::bitset<4> b4{ 0b100 }; // b4 is 0100
    std::bitset<8> b8{ 0b100 }; // b8 is 0000 0100

    std::cout << b4 << ' ' << b8 << '\n';
    std::cout << b4.to_ulong() << ' ' << b8.to_ulong() << '\n';

    b4 = ~b4; // flip b4
    b8 = ~b8; // flip b8

    std::cout << b4 << ' ' << b8 << '\n';
    std::cout << b4.to_ulong() << ' ' << b8.to_ulong() << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
