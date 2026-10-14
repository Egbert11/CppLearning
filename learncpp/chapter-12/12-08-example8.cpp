// ============================================================
// 来源小节：12.8 Null pointers
// 示例说明：解引用前先做非空检查，避免解引用空指针或悬垂指针。
// 原文链接：https://www.learncpp.com/cpp-tutorial/null-pointers/
// 备注：本节代码为按原文描述忠实重建（原 Example 8，原文为片段，
//       此处补出可编译的完整程序）。
// ============================================================
#include <iostream>

int main()
{
    int x { 5 };
    int* ptr { &x }; // Assume ptr is some pointer that may or may not be a null pointer

    // --- 原文示例片段 ---
    if (ptr) // if ptr is not a null pointer
        std::cout << *ptr << '\n'; // okay to dereference
    else
    {
        // do something else that doesn't involve dereferencing ptr
        // (print an error message, do nothing at all, etc...)
        std::cout << "ptr is null, not dereferencing\n";
    }
    // --- 原文示例片段结束 ---

    return 0;
}

// 预期输出：
// 5
