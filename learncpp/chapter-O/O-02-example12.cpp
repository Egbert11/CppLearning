// 来源小节：O.2 Bitwise operators
// 示例说明：用 static_cast 把位运算结果转回窄类型，修复整型提升陷阱后的正确版本。
// 原文链接：https://www.learncpp.com/cpp-tutorial/bitwise-operators/
//
// 预期输出（假定 32 位 int）：
//   00000000000000000000000011110000   （~c 截断到 8 位的正确结果）
//   00000000000000000000000011000000   （c << 6 截断到 8 位的正确结果）
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块）。
#include <bitset>
#include <cstdint>
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::uint8_t c { 0b00001111 };

    std::cout << std::bitset<32>(static_cast<std::uint8_t>(~c))     << '\n'; // correct
    std::cout << std::bitset<32>(static_cast<std::uint8_t>(c << 6)) << '\n'; // correct

    [[maybe_unused]] std::uint8_t cneg { static_cast<std::uint8_t>(~c) }; // no narrowing error
    c = static_cast<std::uint8_t>(~c);                                    // no narrowing warning
    // --- 原文示例片段结束 ---

    return 0;
}
