// 来源小节：O.3 Bit manipulation with bitwise operators and bit masks
// 示例说明：在 std::bitset 上配合掩码进行查询、翻转、设置与清除。
// 原文链接：https://www.learncpp.com/cpp-tutorial/bit-manipulation-with-bitwise-operators-and-bit-masks/
//
// 预期输出：
//   bit 1 is off
//   bit 2 is on
//   bit 1 is on
//   bit 2 is off
//   bit 1 is on
//   bit 2 is on
//   bit 1 is off
//   bit 2 is off
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块）。
#include <bitset>
#include <cstdint>
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    [[maybe_unused]] constexpr std::bitset<8> mask0{ 0b0000'0001 }; // represents bit 0
    [[maybe_unused]] constexpr std::bitset<8> mask1{ 0b0000'0010 }; // represents bit 1
    [[maybe_unused]] constexpr std::bitset<8> mask2{ 0b0000'0100 }; // represents bit 2
    [[maybe_unused]] constexpr std::bitset<8> mask3{ 0b0000'1000 }; // represents bit 3
    [[maybe_unused]] constexpr std::bitset<8> mask4{ 0b0001'0000 }; // represents bit 4
    [[maybe_unused]] constexpr std::bitset<8> mask5{ 0b0010'0000 }; // represents bit 5
    [[maybe_unused]] constexpr std::bitset<8> mask6{ 0b0100'0000 }; // represents bit 6
    [[maybe_unused]] constexpr std::bitset<8> mask7{ 0b1000'0000 }; // represents bit 7

    std::bitset<8> flags{ 0b0000'0101 };

    std::cout << "bit 1 is " << (flags.test(1) ? "on\n" : "off\n");
    std::cout << "bit 2 is " << (flags.test(2) ? "on\n" : "off\n");

    flags ^= (mask1 | mask2); // flip bits 1 and 2
    std::cout << "bit 1 is " << (flags.test(1) ? "on\n" : "off\n");
    std::cout << "bit 2 is " << (flags.test(2) ? "on\n" : "off\n");

    flags |= (mask1 | mask2); // turn bits 1 and 2 on
    std::cout << "bit 1 is " << (flags.test(1) ? "on\n" : "off\n");
    std::cout << "bit 2 is " << (flags.test(2) ? "on\n" : "off\n");

    flags &= ~(mask1 | mask2); // turn bits 1 and 2 off
    std::cout << "bit 1 is " << (flags.test(1) ? "on\n" : "off\n");
    std::cout << "bit 2 is " << (flags.test(2) ? "on\n" : "off\n");
    // --- 原文示例片段结束 ---

    return 0;
}
