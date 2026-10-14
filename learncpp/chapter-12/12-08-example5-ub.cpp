// ============================================================
// 来源小节：12.8 Null pointers
// 示例说明：解引用空指针是未定义行为，多数情况下会使程序崩溃（若指针
//           什么都不指，就没有值可取）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/null-pointers/
// !! -ub：未定义行为演示，可编译但运行会崩溃（Segmentation fault 等）。
// 备注：本节代码为按原文描述忠实重建（原 Example 5）。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int* ptr {}; // Create a null pointer
    std::cout << *ptr << '\n'; // Dereference the null pointer
    // --- 原文示例片段结束 ---

    return 0;
}

// 预期：运行时段错误/崩溃（解引用空指针是未定义行为）。
