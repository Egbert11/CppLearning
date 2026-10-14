// 来源小节：O.3 Bit manipulation with bitwise operators and bit masks
// 示例说明：用 C++14 二进制字面量定义一组位掩码 mask0…mask7。
// 原文链接：https://www.learncpp.com/cpp-tutorial/bit-manipulation-with-bitwise-operators-and-bit-masks/
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块）。
#include <cstdint>
#include <iostream>

// --- 原文示例片段 ---
constexpr std::uint8_t mask0{ 0b0000'0001 }; // represents bit 0
constexpr std::uint8_t mask1{ 0b0000'0010 }; // represents bit 1
constexpr std::uint8_t mask2{ 0b0000'0100 }; // represents bit 2
constexpr std::uint8_t mask3{ 0b0000'1000 }; // represents bit 3
constexpr std::uint8_t mask4{ 0b0001'0000 }; // represents bit 4
constexpr std::uint8_t mask5{ 0b0010'0000 }; // represents bit 5
constexpr std::uint8_t mask6{ 0b0100'0000 }; // represents bit 6
constexpr std::uint8_t mask7{ 0b1000'0000 }; // represents bit 7
// --- 原文示例片段结束 ---

int main()
{
    std::cout << "mask0 = " << static_cast<int>(mask0) << '\n';
    std::cout << "mask5 = " << static_cast<int>(mask5) << '\n';
    std::cout << "mask7 = " << static_cast<int>(mask7) << '\n';

    return 0;
}
