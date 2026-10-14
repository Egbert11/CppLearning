// ============================================================
// 来源小节：12.8 Null pointers
// 示例说明：指针可被"重定向"——把一个空指针改成指向有效对象。
// 原文链接：https://www.learncpp.com/cpp-tutorial/null-pointers/
// 备注：本节代码为按原文描述忠实重建（原 Example 3）。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int* ptr {}; // ptr is a null pointer, and is not holding an address

    int x { 5 };
    ptr = &x; // ptr now pointing at object x (no longer a null pointer)

    std::cout << *ptr << '\n'; // print value of x through dereferenced ptr
    // --- 原文示例片段结束 ---

    return 0;
}

// 预期输出：
// 5
