// 来源小节：O.2 Bitwise operators
// 示例说明：混合打印与位移时必须加括号，否则先打印值再打印 1。
// 原文链接：https://www.learncpp.com/cpp-tutorial/bitwise-operators/
//
// 预期输出：
//   01101   （0110 后面接着打印 1）
//   1100    （(x << 1) 的结果）
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块）。
#include <bitset>
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::bitset<4> x{ 0b0110 };

    std::cout << x << 1 << '\n';   // print value of x (0110), then 1
    std::cout << (x << 1) << '\n'; // print x left shifted by 1 (1100)
    // --- 原文示例片段结束 ---

    return 0;
}
