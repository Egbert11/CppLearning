// 来源小节：O.1 Bit flags and bit manipulation via std::bitset
// 示例说明：用 set() / flip() / reset() / test() 操作 std::bitset<8> 的单个位。
// 原文链接：https://www.learncpp.com/cpp-tutorial/bit-flags-and-bit-manipulation-via-stdbitset/
//
// 预期输出：
//   All the bits: 00001101
//   Bit 3 has value: 1
//   Bit 4 has value: 0
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块）。
#include <bitset>
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::bitset<8> bits{ 0b0000'0101 }; // we need 8 bits, start with bit pattern 0000 0101
    bits.set(3);   // set bit position 3 to 1 (now we have 0000 1101)
    bits.flip(4);  // flip bit 4 (now we have 0001 1101)
    bits.reset(4); // set bit 4 back to 0 (now we have 0000 1101)

    std::cout << "All the bits: " << bits << '\n';
    std::cout << "Bit 3 has value: " << bits.test(3) << '\n';
    std::cout << "Bit 4 has value: " << bits.test(4) << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
