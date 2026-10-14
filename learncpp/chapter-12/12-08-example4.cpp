// ============================================================
// 来源小节：12.8 Null pointers
// 示例说明：用 nullptr 空指针字面量——可用于初始化、赋值、以及把空
//           指针传给函数。就像 true/false 是布尔字面量，nullptr 是
//           空指针字面量。
// 原文链接：https://www.learncpp.com/cpp-tutorial/null-pointers/
// 备注：本节代码为按原文描述忠实重建（原 Example 4）。
//       原文以 someFunction(nullptr) 示意，此处补上该函数定义以便
//       整个程序可编译链接。
// ============================================================
#include <iostream>

void someFunction(int* ptr)
{
    std::cout << "someFunction called with a " << (ptr ? "non-null" : "null") << " pointer\n";
}

int main()
{
    // --- 原文示例片段 ---
    int* ptr { nullptr }; // can use nullptr to initialize a pointer to be a null pointer

    int value { 5 };
    int* ptr2 { &value }; // ptr2 is a valid pointer
    ptr2 = nullptr; // Can assign nullptr to make the pointer a null pointer

    someFunction(nullptr); // we can also pass nullptr to a function that has a pointer parameter
    // --- 原文示例片段结束 ---

    (void)ptr;
    (void)ptr2;
    return 0;
}

// 预期输出：
// someFunction called with a null pointer
