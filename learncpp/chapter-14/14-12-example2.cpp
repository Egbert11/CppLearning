// ============================================================
// 来源小节：14.12 Delegating constructors
// 示例说明：重构——B() 改为先调用 A()，再去重地执行自己的任务。
// 原文链接：https://www.learncpp.com/cpp-tutorial/delegating-constructors/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 2）---
void A()
{
    // statements that do task A
    std::cout << "Task A\n";
}

void B()
{
    A(); // call A() instead of repeating its statements

    // statements that do task B
    std::cout << "Task B\n";
}

int main()
{
    A();
    B();

    return 0;
}

// 预期输出：
// Task A
// Task A
// Task B
