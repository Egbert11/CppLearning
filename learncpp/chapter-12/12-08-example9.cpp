// ============================================================
// 来源小节：12.8 Null pointers
// 示例说明：旧式写法——在指针语境中，整数字面量 0 被特别定义为空值，
//           这是唯一允许把整型字面量赋给指针的情形。现代 C++ 应避免。
// 原文链接：https://www.learncpp.com/cpp-tutorial/null-pointers/
// 备注：本节代码为按原文描述忠实重建（原 Example 9）。
// ============================================================
int main()
{
    // --- 原文示例片段 ---
    float* ptr { 0 }; // ptr is now a null pointer (for example only, don't do this)

    float* ptr2; // ptr2 is uninitialized
    ptr2 = 0; // ptr2 is now a null pointer (for example only, don't do this)
    // --- 原文示例片段结束 ---

    (void)ptr;
    (void)ptr2;

    return 0;
}
