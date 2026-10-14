// ============================================================
// 来源小节：12.7 Introduction to pointers
// 示例说明：三种声明对比——普通 int、int&（左值引用）、int*（指针）。
//           引用与指针都用符号标识，但含义不同。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/
// 备注：本节代码为按原文描述忠实重建（原 Example 5）。
// ============================================================
int main()
{
    // --- 原文示例片段 ---
    int i {};     // a normal int
    int& r { i }; // an lvalue reference to an int
    int* p {};    // a pointer to an int
    // --- 原文示例片段结束 ---

    (void)r;
    (void)p;

    return 0;
}
