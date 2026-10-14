// 来源小节：O.3 Bit manipulation with bitwise operators and bit masks
// 示例说明：用左移 1 << n 定义同样的一组掩码（把单个 1 放到目标位置）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/bit-manipulation-with-bitwise-operators-and-bit-masks/
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块）。
#include <cstdint>
#include <iostream>

// --- 原文示例片段 ---
constexpr std::uint8_t mask0{ 1 << 0 }; // 0000 0001
constexpr std::uint8_t mask1{ 1 << 1 }; // 0000 0010
constexpr std::uint8_t mask2{ 1 << 2 }; // 0000 0100
constexpr std::uint8_t mask3{ 1 << 3 }; // 0000 1000
constexpr std::uint8_t mask4{ 1 << 4 }; // 0001 0000
constexpr std::uint8_t mask5{ 1 << 5 }; // 0010 0000
constexpr std::uint8_t mask6{ 1 << 6 }; // 0100 0000
constexpr std::uint8_t mask7{ 1 << 7 }; // 1000 0000
// --- 原文示例片段结束 ---

int main()
{
    std::cout << "mask0 = " << static_cast<int>(mask0) << '\n';
    std::cout << "mask7 = " << static_cast<int>(mask7) << '\n';

    return 0;
}
