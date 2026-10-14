// ============================================================
// 来源小节：12.2 Value categories (lvalues and rvalues)
// 示例说明：表达式除产生值外还可能有副作用（side effect）：++x 会
//           永久地改变 x 的值，这个改在表达式结束后依然存在。
// 原文链接：https://www.learncpp.com/cpp-tutorial/value-categories-lvalues-and-rvalues/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段（原 Example 2）---
    int x { 5 };

    ++x; // side effect: x is permanently incremented

    std::cout << x << '\n'; // prints 6

    return 0;
}

// 预期输出：
// 6
