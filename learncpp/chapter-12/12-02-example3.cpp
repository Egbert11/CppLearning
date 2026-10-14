// ============================================================
// 来源小节：12.2 Value categories (lvalues and rvalues)
// 示例说明：用 auto 展示表达式的"类型"在编译期即可确定：12 / 4 的
//           类型是 int，12.0 / 4 的类型是 double。类型决定了编译器
//           能否接受某个表达式。
// 原文链接：https://www.learncpp.com/cpp-tutorial/value-categories-lvalues-and-rvalues/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段（原 Example 3）---
    auto a { 12 / 4 };   // int division, result is int 3
    auto b { 12.0 / 4 }; // floating-point division, result is double 3.0

    std::cout << a << '\n';
    std::cout << b << '\n';

    return 0;
}

// 预期输出：
// 3
// 3
