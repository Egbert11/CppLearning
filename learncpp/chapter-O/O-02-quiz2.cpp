// ============================================================
// 来源小节：O.2 Bitwise operators
// 示例说明：测验 2 解答——用 test() 与 set() 实现 4 位位集合的
//           左循环移位 rotl（把最高位移出的位补回最低位）。
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
    const bool leftbit{ bits.test(3) };

    bits <<= 1; // do the left rotation

    if (leftbit)
        bits.set(0);

    return bits;
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
