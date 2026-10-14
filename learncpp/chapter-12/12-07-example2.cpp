// ============================================================
// 来源小节：12.7 Introduction to pointers
// 示例说明：变量 x 与其左值引用 ref 解析到同一地址——引用只是别名，
//           使用引用就是去往同一块内存。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/
// 备注：本节代码为按原文描述忠实重建（原 Example 2）。
// ============================================================
int main()
{
    // --- 原文示例片段 ---
    int x {};
    int& ref { x }; // ref is an alias for x, they resolve to the same address

    (void)ref;
    // --- 原文示例片段结束 ---

    return 0;
}
