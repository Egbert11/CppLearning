// 来源小节：20.3 Recursion（Quiz 2）
// 示例说明：递归求一个整数各位数字之和。x < 10 时返回 x 作为 base case，
//           否则返回 sumDigits(x / 10) + x % 10。
// 原文链接：https://www.learncpp.com/cpp-tutorial/recursion/
// 说明：本节代码为按原文描述重建。
// 预期输出：25（即 9 + 3 + 4 + 2 + 7）

#include <iostream>

// --- 原文示例片段 ---
int sumDigits(int x)
{
    if (x < 10)
        return x;
    else
        return sumDigits(x / 10) + x % 10;
}
// --- 原文示例片段结束 ---

int main()
{
    std::cout << sumDigits(93427) << '\n';

    return 0;
}
