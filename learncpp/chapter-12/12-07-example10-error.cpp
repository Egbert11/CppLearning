// ============================================================
// 来源小节：12.7 Introduction to pointers
// 示例说明：指针类型必须与所指向对象匹配——int* 不能指向 double，反之
//           亦然（下一节的例外待讲）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/
// !! -error：预期编译失败，勿修复。
//   预期错误：cannot convert 'double*' to 'int*'（iPtr2 行）；
//             以及 cannot convert 'int*' to 'double*'（dPtr2 行）。
// 备注：本节代码为按原文描述忠实重建（原 Example 10）。
// ============================================================
int main()
{
    // --- 原文示例片段 ---
    int i {};
    double d {};

    int* iPtr { &i };     // okay: int* holds the address of an int
    int* iPtr2 { &d };    // error: int* can't hold the address of a double (type mismatch)
    double* dPtr { &d };  // okay: double* holds the address of a double
    double* dPtr2 { &i }; // error: double* can't hold the address of an int (type mismatch)
    // --- 原文示例片段结束 ---

    return 0;
}
