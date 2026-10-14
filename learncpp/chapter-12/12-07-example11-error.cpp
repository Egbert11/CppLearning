// ============================================================
// 来源小节：12.7 Introduction to pointers
// 示例说明：不允许用字面量初始化指针（唯一的例外是空指针相关，见 12.8）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/
// !! -error：预期编译失败，勿修复。
//   预期错误：cannot convert 'int' to 'int*'（ptr 行）；
//             以及 cannot convert 'double' to 'double*'（dPtr 行）。
// 备注：本节代码为按原文描述忠实重建（原 Example 11）。
// ============================================================
int main()
{
    // --- 原文示例片段 ---
    int* ptr{ 5 };       // compile error: can't assign an int literal to an int*
    double* dPtr{ 3.7 }; // compile error: can't assign a double literal to a double*
    // --- 原文示例片段结束 ---

    return 0;
}
