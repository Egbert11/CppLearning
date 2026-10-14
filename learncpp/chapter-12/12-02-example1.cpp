// ============================================================
// 来源小节：12.2 Value categories (lvalues and rvalues)
// 示例说明：表达式 2 + 3 求值得到一个值（5），把它打印出来。
// 原文链接：https://www.learncpp.com/cpp-tutorial/value-categories-lvalues-and-rvalues/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段（原 Example 1）---
    std::cout << 2 + 3 << '\n'; // 2 + 3 evaluates to the value 5

    return 0;
}

// 预期输出：
// 5
