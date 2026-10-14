// 来源小节：O.3 Bit manipulation with bitwise operators and bit masks
// 示例说明：查询/设置/清除/翻转四种位操作的总结口诀片段。
// 原文链接：https://www.learncpp.com/cpp-tutorial/bit-manipulation-with-bitwise-operators-and-bit-masks/
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块）。
#include <cstdint>
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    constexpr std::uint8_t option4{ 0b0000'1000 };
    constexpr std::uint8_t option5{ 0b0001'0000 };
    std::uint8_t flags{ 0b0000'0000 };

    if (flags & option4) // Query: is bit 3 set?
        std::cout << "bit 3 is set\n";
    else
        std::cout << "bit 3 is not set\n";

    flags |= (option4 | option5);   // Set: turn bits on
    std::cout << "after set: " << static_cast<int>(flags) << '\n';

    flags &= ~(option4 | option5);  // Clear: turn bits off
    std::cout << "after clear: " << static_cast<int>(flags) << '\n';

    flags ^= (option4 | option5);   // Flip: invert bits
    std::cout << "after flip: " << static_cast<int>(flags) << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
