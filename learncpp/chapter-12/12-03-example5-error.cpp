// ============================================================
// 来源小节：12.3 Lvalue references
// 示例说明：非 const 左值引用只能绑定"可修改左值"——不能绑定 const
//           对象，也不能绑定右值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lvalue-references/
// !! -error：预期编译失败，勿修复。
//   预期错误：binding reference of type 'int&' to 'const int' discards qualifiers；
//             以及 cannot bind non-const lvalue reference of type 'int&' to an rvalue。
// 备注：本节代码为按原文描述忠实重建（原 Example 5）。
// ============================================================
int main()
{
    // --- 原文示例片段 ---
    int x { 5 };
    int& ref { x }; // okay: non-const lvalue reference bound to a modifiable lvalue

    const int y { 5 };
    int& invalidRef { y };  // invalid: non-const lvalue reference can't bind to a non-modifiable lvalue
    int& invalidRef2 { 0 }; // invalid: non-const lvalue reference can't bind to an rvalue
    // --- 原文示例片段结束 ---

    return 0;
}
