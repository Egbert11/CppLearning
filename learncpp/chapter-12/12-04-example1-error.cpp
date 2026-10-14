// ============================================================
// 来源小节：12.4 Lvalue references to const
// 示例说明：非 const 左值引用不能绑定 const 对象——否则就能通过引用
//           改掉 const 变量。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lvalue-references-to-const/
// !! -error：预期编译失败，勿修复。
//   预期错误：binding reference of type 'int&' to 'const int' discards qualifiers。
// 备注：本节代码为按原文描述忠实重建（原 Example 1）。
// ============================================================
int main()
{
    // --- 原文示例片段 ---
    const int x { 5 }; // x is a non-modifiable (const) lvalue
    int& ref { x };    // error: ref can not bind to non-modifiable lvalue
    // --- 原文示例片段结束 ---

    return 0;
}
