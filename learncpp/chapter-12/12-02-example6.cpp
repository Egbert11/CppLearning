// ============================================================
// 来源小节：12.2 Value categories (lvalues and rvalues)
// 示例说明：左值初始化左值；并对比"可修改左值"（x）与"不可修改左值"
//           （const d）。不可修改左值（const/constexpr）的值不能被改变。
// 原文链接：https://www.learncpp.com/cpp-tutorial/value-categories-lvalues-and-rvalues/
// 备注：本节代码为按原文描述忠实重建；对应原文 Example 6 与 Example 7。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段（原 Example 6 / Example 7）---
    int x { 5 };          // x is a modifiable lvalue
    int y { x };          // x is an lvalue expression (its value is used here)

    const double d { 4.5 }; // d is a non-modifiable lvalue

    std::cout << x << ' ' << y << ' ' << d << '\n';

    return 0;
}

// 预期输出：
// 5 5 4.5
