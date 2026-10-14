// 来源小节：O.1 Bit flags and bit manipulation via std::bitset
// 示例说明：用 size() / count() / all() / any() / none() 查询一个位集合。
// 原文链接：https://www.learncpp.com/cpp-tutorial/bit-flags-and-bit-manipulation-via-stdbitset/
//
// 预期输出：
//   8 bits are in the bitset
//   3 bits are set to true
//   All bits are true: false
//   Some bits are true: true
//   No bits are true: false
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块）。
#include <bitset>
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::bitset<8> bits{ 0b0000'1101 };
    std::cout << bits.size() << " bits are in the bitset\n";
    std::cout << bits.count() << " bits are set to true\n";

    std::cout << std::boolalpha;
    std::cout << "All bits are true: " << bits.all() << '\n';
    std::cout << "Some bits are true: " << bits.any() << '\n';
    std::cout << "No bits are true: " << bits.none() << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
