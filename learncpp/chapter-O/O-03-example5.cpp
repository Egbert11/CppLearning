// 来源小节：O.3 Bit manipulation with bitwise operators and bit masks
// 示例说明：用位或赋值 flags |= maskN 设置某位；把多个掩码先或起来可一次设置多个位。
// 原文链接：https://www.learncpp.com/cpp-tutorial/bit-manipulation-with-bitwise-operators-and-bit-masks/
//
// 预期输出：
//   bit 1 is off
//   bit 1 is on
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

    std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");

    flags |= mask1; // turn on bit 1

    std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");

    flags |= (mask4 | mask5); // turn bits 4 and 5 on at the same time
    // --- 原文示例片段结束 ---

    return 0;
}
