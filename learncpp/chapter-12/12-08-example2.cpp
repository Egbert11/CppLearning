// ============================================================
// 来源小节：12.8 Null pointers
// 示例说明：值初始化指针（`{}`）会把它变成空指针（null pointer），
//           即"什么也不指"。未用有效对象地址初始化指针时应这样做。
// 原文链接：https://www.learncpp.com/cpp-tutorial/null-pointers/
// 备注：本节代码为按原文描述忠实重建（原 Example 2）。
// ============================================================
int main()
{
    // --- 原文示例片段 ---
    int* ptr {}; // ptr is now a null pointer, and is not holding an address
    // --- 原文示例片段结束 ---

    (void)ptr;

    return 0;
}
