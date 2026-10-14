// ============================================================
// 来源小节：12.7 Introduction to pointers
// 示例说明：通过赋值改变指针的指向——把 ptr 从指向 x 改为指向 y。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/
// 备注：本节代码为按原文描述忠实重建（原 Example 12）。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x{ 5 };
    int* ptr{ &x }; // ptr points at x
    std::cout << *ptr << '\n';

    int y{ 6 };
    ptr = &y; // ptr now points at y
    std::cout << *ptr << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}

// 预期输出：
// 5
// 6
