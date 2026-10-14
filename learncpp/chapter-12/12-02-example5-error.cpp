// ============================================================
// 来源小节：12.2 Value categories (lvalues and rvalues)
// 示例说明：赋值要求左操作数是"可修改的左值"，右操作数是右值。
//           x = 5 合法；5 = x 非法（5 是右值）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/value-categories-lvalues-and-rvalues/
// !! -error：预期编译失败，勿修复。
//   预期错误：lvalue required as left operand of assignment（5 = x 一行）。
// 备注：本节代码为按原文描述忠实重建；对应原文 Example 5 与 Example 10。
// ============================================================
int main()
{
    // --- 原文示例片段（原 Example 5 / Example 10）---
    int x { 5 };

    x = 5; // okay: x is a modifiable lvalue, 5 is an rvalue

    // assignment requires the left operand to be a modifiable lvalue
    // and the right operand to be an rvalue
    5 = x; // error: 5 is an rvalue (not a modifiable lvalue)

    return 0;
}
