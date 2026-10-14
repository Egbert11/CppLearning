// ============================================================
// 来源小节：12.7 Introduction to pointers
// 示例说明：一个变量、一个引用、一个未初始化指针。指针默认不被初始化，
//           未初始化的指针称"野指针"（wild pointer），持有垃圾地址，
//           解引用它是未定义行为。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/
// 备注：本节代码为按原文描述忠实重建（原 Example 6）。
//       ptr 未初始化即使用是坏实践，这里仅为演示，不应当解引用它。
// ============================================================
int main()
{
    // --- 原文示例片段 ---
    int x { 5 };
    int& ref { x };
    int* ptr; // a pointer (uninitialized) -- "wild pointer"
    // --- 原文示例片段结束 ---

    (void)ref;
    (void)ptr;

    return 0;
}
