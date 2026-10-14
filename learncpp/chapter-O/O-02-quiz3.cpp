// ============================================================
// 来源小节：O.2 Bitwise operators
// 示例说明：测验 3（附加题）解答——只用位运算符实现左循环移位 rotl。
// 原文链接：https://www.learncpp.com/cpp-tutorial/bitwise-operators/
// ============================================================
//
// 预期输出：
//   0010
//   0011
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块）。
#include <bitset>
#include <iostream>

std::bitset<4> rotl(std::bitset<4> bits)
{
    // --- 原文示例片段 ---
    // bits << 1 does the left shift
    // bits >> 3 handles the bits that were shifted off the left
    return (bits << 1) | (bits >> 3);
    // --- 原文示例片段结束 ---
}

int main()
{
    std::bitset<4> bits1{ 0b0001 };
    std::cout << rotl(bits1) << '\n';

    std::bitset<4> bits2{ 0b1001 };
    std::cout << rotl(bits2) << '\n';

    return 0;
}
