// 来源小节：20.x Chapter 20 summary and quiz（Quiz 2b）
// 示例说明：递归函数没有终止条件（base case）。value 会一直减小并向负数前进，
//           递归永不停止，直到栈溢出。此外最终还会发生有符号整数下溢（UB）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-20-summary-and-quiz/
// 说明：本节代码为按原文描述重建。
// 预期行为：栈溢出崩溃。**请勿运行**。

// --- 原文示例片段 ---
int sumTo(int value)
{
    return value + sumTo(value - 1); // no termination condition
}
// --- 原文示例片段结束 ---

int main()
{
    // Not calling sumTo() to avoid the inevitable stack overflow at runtime.
    return 0;
}
