// ============================================================
// 来源小节：12.14 Type deduction with pointers, references, and const
// 示例说明：最基本的 auto 类型推导——从 int 初始化器推导出 int。
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-with-pointers-references-and-const/
// 备注：本节代码为按原文清单忠实重建（原 Example 1）。
// ============================================================

int main()
{
    // --- 原文示例片段 ---
    int a { 5 };
    auto b { a }; // b deduced as an int
    // --- 原文示例片段结束 ---

    return b;
}
