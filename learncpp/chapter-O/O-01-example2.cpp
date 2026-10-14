// 来源小节：O.1 Bit flags and bit manipulation via std::bitset
// 示例说明：声明一个 8 位的标志集合 std::bitset<8>，并输出其位数以印证位位置参考。
// 原文链接：https://www.learncpp.com/cpp-tutorial/bit-flags-and-bit-manipulation-via-stdbitset/
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块）。
//
// 位位置参考（从右往左、从 0 开始编号）：
//   76543210  Bit position
//   00000101  Bit sequence
#include <bitset> // for std::bitset
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::bitset<8> mybitset {}; // 8 bits in size means room for 8 flags
    // --- 原文示例片段结束 ---

    std::cout << "mybitset holds " << mybitset.size() << " flags\n";
    std::cout << "initial value: " << mybitset << '\n';

    return 0;
}
