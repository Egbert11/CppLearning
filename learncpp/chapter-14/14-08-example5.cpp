// ============================================================
// 来源小节：14.8 The benefits of data hiding (encapsulation)
// 示例说明：struct 直接公开三个成员，可被任意赋值和读取——实现（如何存储）暴露给用户。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-benefits-of-data-hiding-encapsulation/
// 备注：本节代码为按原文描述忠实重建。原文未给出输出。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 5）---
struct Something
{
    int value1 {};
    int value2 {};
    int value3 {};
};

int main()
{
    Something something;
    something.value1 = 5; // direct access to the data member
    std::cout << something.value1 << '\n';

    return 0;
}

// 预期输出：
// 5
