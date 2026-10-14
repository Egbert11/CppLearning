// 来源小节：O.2 Bitwise operators
// 示例说明：区分同一个 << 符号的两种含义——左移（左操作数是整型）与流输出（左操作数是流）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/bitwise-operators/
//
// 预期输出：1000
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块）。
#include <bitset>
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    unsigned int x { 0b0100 };
    x = x << 1; // use operator<< for left shift
    std::cout << std::bitset<4>{ x } << '\n'; // use operator<< for output
    // --- 原文示例片段结束 ---

    return 0;
}
