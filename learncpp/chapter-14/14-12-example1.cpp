// ============================================================
// 来源小节：14.12 Delegating constructors
// 示例说明：冗余示例——B() 重复了 A() 的全部语句。
// 原文链接：https://www.learncpp.com/cpp-tutorial/delegating-constructors/
// 备注：本节代码为按原文描述忠实重建。原文用“// statements that do task A”等
//       注释占位，这里换成实际的打印语句以便运行。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 1）---
void A()
{
    // statements that do task A
    std::cout << "Task A\n";
}

void B()
{
    // statements that do task A (duplicated!)
    std::cout << "Task A\n";

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
