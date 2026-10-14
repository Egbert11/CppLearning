// 来源小节：O.3 Bit manipulation with bitwise operators and bit masks
// 示例说明：C++11 及更早没有二进制字面量时，用十六进制字面量定义同样的一组掩码。
// 原文链接：https://www.learncpp.com/cpp-tutorial/bit-manipulation-with-bitwise-operators-and-bit-masks/
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块）。
#include <cstdint>
#include <iostream>

// --- 原文示例片段 ---
constexpr std::uint8_t mask0{ 0x01 }; // hex for 0000 0001
constexpr std::uint8_t mask1{ 0x02 }; // hex for 0000 0010
constexpr std::uint8_t mask2{ 0x04 }; // hex for 0000 0100
constexpr std::uint8_t mask3{ 0x08 }; // hex for 0000 1000
constexpr std::uint8_t mask4{ 0x10 }; // hex for 0001 0000
constexpr std::uint8_t mask5{ 0x20 }; // hex for 0010 0000
constexpr std::uint8_t mask6{ 0x40 }; // hex for 0100 0000
constexpr std::uint8_t mask7{ 0x80 }; // hex for 1000 0000
// --- 原文示例片段结束 ---

int main()
{
    std::cout << "mask0 = " << static_cast<int>(mask0) << '\n';
    std::cout << "mask7 = " << static_cast<int>(mask7) << '\n';

    return 0;
}
