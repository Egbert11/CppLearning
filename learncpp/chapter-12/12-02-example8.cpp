// ============================================================
// 来源小节：12.2 Value categories (lvalues and rvalues)
// 示例说明：左值到右值转换——当需要右值而提供了左值时，编译器会把
//           左值求值成它的值。x = y 里 y 是左值但被转换为右值；
//           x = x + 1 里左侧 x 是左值，右侧 x 被转换为右值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/value-categories-lvalues-and-rvalues/
// 备注：本节代码为按原文描述忠实重建；对应原文 Example 11 与 Example 12。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段（原 Example 11 / Example 12）---
    int x { 5 };
    int y { 6 };

    x = y;     // y is an lvalue, but it is converted to an rvalue (its value 6) here

    x = x + 1; // left x is an lvalue; the right x is converted to an rvalue (its value 6), then + 1
    // --- 原文示例片段结束 ---

    std::cout << x << '\n'; // prints 7

    return 0;
}

// 预期输出：
// 7
