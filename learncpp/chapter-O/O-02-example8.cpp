// 来源小节：O.2 Bitwise operators
// 示例说明：多重按位与（某一列只有当所有位都为 1 时结果才为 1）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/bitwise-operators/
//
// 预期输出：0001
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块）。
#include <bitset>
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::cout << (std::bitset<4>{ 0b0001 } & std::bitset<4>{ 0b0011 } & std::bitset<4>{ 0b0111 }) << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
