// ============================================================
// 来源小节：12.7 Introduction to pointers
// 示例说明：三种指针初始化——未初始化（垃圾地址）、值初始化（空指针）、
//           以对象地址初始化。指针应当总是初始化。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/
// 备注：本节代码为按原文描述忠实重建（原 Example 8）。
//       ptr1 是野指针，仅作演示，绝不要解引用它。
// ============================================================
#include <iostream>

int main()
{
    int x { 5 };

    // --- 原文示例片段 ---
    [[maybe_unused]] int* ptr1;      // uninitialized pointer (wild pointer) -- DON'T DO THIS
    [[maybe_unused]] int* ptr2 {};   // value-initialized pointer (null pointer)
    int* ptr3 { &x };                // pointer initialized with the address of x
    // --- 原文示例片段结束 ---

    std::cout << *ptr3 << '\n'; // prints 5

    return 0;
}

// 预期输出：
// 5
