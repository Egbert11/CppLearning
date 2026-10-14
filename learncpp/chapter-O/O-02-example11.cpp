// 来源小节：O.2 Bitwise operators
// 示例说明：位运算赋值运算符 >>= 会修改左操作数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/bitwise-operators/
//
// 预期输出：0010
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块）。
#include <bitset>
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::bitset<4> bits { 0b0100 };
    bits >>= 1;
    std::cout << bits << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
