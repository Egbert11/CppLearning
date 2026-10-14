// 来源小节：O.3 Bit manipulation with bitwise operators and bit masks
// 示例说明：改用 std::bitset<32> 传选项，调用点可读性大幅提升。
// 原文链接：https://www.learncpp.com/cpp-tutorial/bit-manipulation-with-bitwise-operators-and-bit-masks/
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块）。
#include <bitset>
#include <cstdint>
#include <iostream>

// --- 原文示例片段 ---
constexpr std::uint32_t option10{ 0b0000'0000'0000'0000'0000'0010'0000'0000 }; // bit 9
constexpr std::uint32_t option32{ 0b1000'0000'0000'0000'0000'0000'0000'0000 }; // bit 31

void someFunction(std::bitset<32> options)
{
    std::cout << "options: " << options << '\n';
}

int main()
{
    someFunction(option10 | option32);
    return 0;
}
// --- 原文示例片段结束 ---
