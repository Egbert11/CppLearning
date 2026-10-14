// 来源小节：O.3 Bit manipulation with bitwise operators and bit masks
// 示例说明：同上，但用 std::bitset<8> 掩码，并用 .any() 查询位状态。
// 原文链接：https://www.learncpp.com/cpp-tutorial/bit-manipulation-with-bitwise-operators-and-bit-masks/
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块）。
#include <bitset>
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    // Define a bunch of physical/emotional states
    [[maybe_unused]] constexpr std::bitset<8> isHungry{   0b0000'0001 };
    [[maybe_unused]] constexpr std::bitset<8> isSad{      0b0000'0010 };
    [[maybe_unused]] constexpr std::bitset<8> isMad{      0b0000'0100 };
    [[maybe_unused]] constexpr std::bitset<8> isHappy{    0b0000'1000 };
    [[maybe_unused]] constexpr std::bitset<8> isLaughing{ 0b0001'0000 };
    [[maybe_unused]] constexpr std::bitset<8> isAsleep{   0b0010'0000 };
    [[maybe_unused]] constexpr std::bitset<8> isDead{     0b0100'0000 };
    [[maybe_unused]] constexpr std::bitset<8> isCrying{   0b1000'0000 };

    std::bitset<8> me{}; // all flags/options turned off to start
    me |= (isHappy | isLaughing); // I am happy and laughing
    me &= ~isLaughing; // I am no longer laughing

    // Query a few states
    std::cout << "I am happy: " << (me & isHappy).any() << '\n';
    std::cout << "I am laughing: " << (me & isLaughing).any() << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
