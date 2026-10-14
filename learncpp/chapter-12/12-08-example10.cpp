// ============================================================
// 来源小节：12.8 Null pointers
// 示例说明：旧式写法——来自 C 的预处理器宏 NULL（定义于 <cstddef>），
//           同样表示空指针。现代 C++ 中 0 与 NULL 都应避免。
// 原文链接：https://www.learncpp.com/cpp-tutorial/null-pointers/
// 备注：本节代码为按原文描述忠实重建（原 Example 10）。
// ============================================================
#include <cstddef> // for NULL

int main()
{
    // --- 原文示例片段 ---
    double* ptr { NULL }; // ptr is a null pointer

    double* ptr2; // ptr2 is uninitialized
    ptr2 = NULL; // ptr2 is now a null pointer
    // --- 原文示例片段结束 ---

    (void)ptr;
    (void)ptr2;

    return 0;
}
