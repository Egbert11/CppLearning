// ============================================================
// 来源小节：12.3 Lvalue references
// 示例说明：引用必须被初始化——未初始化的引用是非法的。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lvalue-references/
// !! -error：预期编译失败，勿修复。
//   预期错误：'invalidRef' declared as reference but not initialized
//             （引用声明但未初始化）。
// 备注：本节代码为按原文描述忠实重建（原 Example 4）。
// ============================================================
int main()
{
    // --- 原文示例片段 ---
    int& invalidRef; // error: references must be initialized

    int x { 5 };
    int& ref { x }; // okay: reference to int is bound to int variable
    // --- 原文示例片段结束 ---

    return 0;
}
