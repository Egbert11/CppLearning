// 来源小节：20.3 Recursion
// 示例说明：故意写坏的递归——countDown() 没有终止条件，无限调用自身，
//           每次调用都压栈而从不返回，最终栈溢出。
// 原文链接：https://www.learncpp.com/cpp-tutorial/recursion/
// 说明：本节代码为按原文描述重建。
// 预期行为：先打印 push 5 / push 4 / ... 直到 count 变成负数（原文作者运行到 -11732 附近），
//           然后因栈溢出崩溃。**请勿运行**。
// Author's note：结尾的调用是"尾调用（tail call）"，编译器通常可以把它优化成迭代函数，
//               那样就不会耗尽栈；但优化与否是实现相关的，不能依赖。

#include <iostream>

// --- 原文示例片段 ---
void countDown(int count)
{
    std::cout << "push " << count << '\n';
    countDown(count-1); // countDown() calls itself recursively
}

int main()
{
    countDown(5);

    return 0;
}
// --- 原文示例片段结束 ---
