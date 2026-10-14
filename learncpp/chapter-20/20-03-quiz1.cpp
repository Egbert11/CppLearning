// 来源小节：20.3 Recursion（Quiz 1）
// 示例说明：递归计算 n 的阶乘（factorial），n <= 0 时返回 1 作为 base case。
// 原文链接：https://www.learncpp.com/cpp-tutorial/recursion/
// 说明：本节代码为按原文描述重建。
// 预期输出（前 7 个阶乘）：
//   1 1 2 6 24 120 720

#include <iostream>

// --- 原文示例片段 ---
int factorial(int n)
{
    if (n <= 0)
        return 1;
    else
        return factorial(n - 1) * n;
}
// --- 原文示例片段结束 ---

int main()
{
    for (int count{ 0 }; count < 7; ++count)
        std::cout << factorial(count) << ' ';
    std::cout << '\n';

    return 0;
}
