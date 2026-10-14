// ============================================================
// 来源小节：12.8 Null pointers
// 示例说明：用条件语句显式地把指针与 nullptr 比较，判断它是否为空。
// 原文链接：https://www.learncpp.com/cpp-tutorial/null-pointers/
// 备注：本节代码为按原文描述忠实重建（原 Example 6）。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x { 5 };
    int* ptr { &x };

    if (ptr == nullptr) // explicit test for equivalence
        std::cout << "ptr is null\n";
    else
        std::cout << "ptr is non-null\n";

    int* nullPtr {};
    std::cout << "nullPtr is " << (nullPtr==nullptr ? "null\n" : "non-null\n"); // explicit test for equivalence
    // --- 原文示例片段结束 ---

    return 0;
}

// 预期输出：
// ptr is non-null
// nullPtr is null
