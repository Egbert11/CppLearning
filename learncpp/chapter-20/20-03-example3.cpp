// 来源小节：20.3 Recursion
// 示例说明：递归计算 1 到 sumto 的和，演示两个 base case（非正数、等于 1）
//           以及递归累积。原文展示了 sumTo(5) 展开到 sumTo(1) 再回卷得到 15 的过程。
// 原文链接：https://www.learncpp.com/cpp-tutorial/recursion/
// 说明：本节代码为按原文描述重建。
// 预期输出：15

#include <iostream>

// --- 原文示例片段 ---
int sumTo(int sumto)
{
    if (sumto <= 0)
        return 0; // base case (termination condition) when user passed in an unexpected argument (0 or negative)
    else if (sumto == 1)
        return 1; // base case (termination condition). This is the trivial case that we know the answer to.

    return sumTo(sumto - 1) + sumto; // recursive function call
}
// --- 原文示例片段结束 ---

int main()
{
    // 原文推荐使用 sumto - 1 而不是 --sumto：
    // 在一个表达式里对一个变量多次施加副作用（如自减）是未定义行为。
    std::cout << sumTo(5) << '\n';

    return 0;
}
