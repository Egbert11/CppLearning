// 来源小节：20.x Chapter 20 summary and quiz（Quiz 2d）
// 示例说明：局部数组太大，无法在栈上分配（100000000 个 int 约 400MB，远超栈上限）。
//           应当改为动态分配（例如 std::vector 或 new）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-20-summary-and-quiz/
// 说明：本节代码为按原文描述重建。
// 预期行为：栈溢出崩溃。**请勿运行**。

#include <iostream>

// --- 原文示例片段 ---
int main()
{
    int array[100000000]{}; // the array is too large to be allocated on the stack

    for (const auto& element : array)
        std::cout << element << ' ';

    return 0;
}
// --- 原文示例片段结束 ---
