// ============================================================
// 来源小节：12.2 Value categories (lvalues and rvalues)
// 示例说明：值类别速查——区分字面量、变量、函数返回值、运算结果、
//           强制转换结果的左右值属性。
// 原文链接：https://www.learncpp.com/cpp-tutorial/value-categories-lvalues-and-rvalues/
// !! -warning：预期产生警告（-Wunused-value），因为多条语句只求值、
//   不作他用，正是这些"纯表达式"用来演示值类别。
// 备注：本节代码为按原文描述忠实重建；对应原文 Example 8 与 Example 9。
// ============================================================
#include <iostream>

int return5()
{
    return 5;
}

int main()
{
    // --- 原文示例片段（原 Example 8 / Example 9）---
    int x { 5 };            // x is a modifiable lvalue
    const double d { 4.5 }; // d is a non-modifiable lvalue

    5;                   // 5 is an rvalue (literal)
    1.2;                 // 1.2 is an rvalue (literal)
    x;                   // x is an lvalue
    d;                   // d is an lvalue
    return5();           // return5() is an rvalue (the returned value is a temporary object)
    x + 1;               // x + 1 is an rvalue (the result is a temporary object)
    static_cast<int>(d); // static_cast<int>(d) is an rvalue (the result is a temporary object)
    // --- 原文示例片段结束 ---

    std::cout << "see comments for value categories\n";

    return 0;
}
