// ============================================================
// 来源小节：12.9 Pointers and const
// 示例说明：普通指针不能指向 const 变量。若允许，就能通过解引用修改一个
//           被声明为常量的值，破坏其 const 性。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointers-and-const/
// !! -error：预期编译失败，请勿修复。
//    预期错误（gcc）：invalid conversion from 'const int*' to 'int*'
//    （从 const int* 到 int* 的非法转换）。
// 备注：本节代码为按原文清单忠实重建（原 Example 2）。
// ============================================================

int main()
{
    // --- 原文示例片段 ---
    const int x { 5 }; // x is now const
    int* ptr { &x };   // compile error: cannot convert from const int* to int*
    // --- 原文示例片段结束 ---

    return 0;
}
