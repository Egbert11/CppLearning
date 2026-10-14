// ============================================================
// 来源小节：12.7 Introduction to pointers
// 示例说明：一行声明多个变量的陷阱——星号必须对每个变量重复，否则
//           只有第一个变量是指针，其余只是普通 int。这也是"一行只做
//           一个定义"的又一理由。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/
// 备注：本节代码为按原文描述忠实重建（原 Example 7）。
// ============================================================
int main()
{
    // --- 原文示例片段 ---
    [[maybe_unused]] int* ptr1, ptr2; // WRONG: ptr1 is int*, but ptr2 is just an int!
    [[maybe_unused]] int* ptr3, * ptr4; // right: both ptr3 and ptr4 are pointers to int
    // --- 原文示例片段结束 ---

    return 0;
}
