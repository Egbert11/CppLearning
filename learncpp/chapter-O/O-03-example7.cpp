// 来源小节：O.3 Bit manipulation with bitwise operators and bit masks
// 示例说明：用位异或赋值 flags ^= maskN 翻转某位；组合掩码可一次翻转多个位。
// 原文链接：https://www.learncpp.com/cpp-tutorial/bit-manipulation-with-bitwise-operators-and-bit-masks/
//
// 预期输出：
//   bit 2 is on
//   bit 2 is off
//   bit 2 is on
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块）。
#include <cstdint>
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    [[maybe_unused]] constexpr std::uint8_t mask0{ 0b0000'0001 }; // represents bit 0
    [[maybe_unused]] constexpr std::uint8_t mask1{ 0b0000'0010 }; // represents bit 1
    [[maybe_unused]] constexpr std::uint8_t mask2{ 0b0000'0100 }; // represents bit 2
    [[maybe_unused]] constexpr std::uint8_t mask3{ 0b0000'1000 }; // represents bit 3
    [[maybe_unused]] constexpr std::uint8_t mask4{ 0b0001'0000 }; // represents bit 4
    [[maybe_unused]] constexpr std::uint8_t mask5{ 0b0010'0000 }; // represents bit 5
    [[maybe_unused]] constexpr std::uint8_t mask6{ 0b0100'0000 }; // represents bit 6
    [[maybe_unused]] constexpr std::uint8_t mask7{ 0b1000'0000 }; // represents bit 7

    std::uint8_t flags{ 0b0000'0101 }; // 8 bits in size means room for 8 flags

    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");

    flags ^= mask2; // flip bit 2
    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");

    flags ^= mask2; // flip bit 2 back
    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");

    flags ^= (mask4 | mask5); // flip bits 4 and 5 at the same time
    // --- 原文示例片段结束 ---

    return 0;
}
