// ============================================================
// 来源小节：12.3 Lvalue references
// 示例说明：引用的类型通常必须与所引用对象匹配；类型不符时编译器会
//           尝试隐式转换，而转换结果是右值，非 const 左值引用无法
//           绑定右值，于是编译失败。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lvalue-references/
// !! -error：预期编译失败，勿修复。
//   预期错误：narrowing conversion（double→int 被列表初始化拒绝）；
//             以及 cannot bind non-const lvalue reference to an rvalue。
// 备注：本节代码为按原文描述忠实重建（原 Example 6）。
// ============================================================
int main()
{
    // --- 原文示例片段 ---
    int x { 5 };
    int& ref { x }; // okay: referenced type (int) matches type of initializer

    double d { 6.0 };
    int& invalidRef { d };     // invalid: conversion of double to int is narrowing conversion, disallowed by list initialization
    double& invalidRef2 { x }; // invalid: non-const lvalue reference can't bind to rvalue (result of converting x to double)
    // --- 原文示例片段结束 ---

    return 0;
}
