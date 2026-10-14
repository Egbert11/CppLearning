// ============================================================
// 来源小节：12.8 Null pointers
// 示例说明：利用隐式布尔转换——空指针转为 false，非空指针转为 true。
//           因此 if (ptr) 就足够，无需显式比较。
// 原文链接：https://www.learncpp.com/cpp-tutorial/null-pointers/
// 备注：本节代码为按原文描述忠实重建（原 Example 7）。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x { 5 };
    int* ptr { &x };

    // pointers convert to Boolean false if they are null, and Boolean true if they are non-null
    if (ptr) // implicit conversion to Boolean
        std::cout << "ptr is non-null\n";
    else
        std::cout << "ptr is null\n";

    int* nullPtr {};
    std::cout << "nullPtr is " << (nullPtr ? "non-null\n" : "null\n"); // implicit conversion to Boolean
    // --- 原文示例片段结束 ---

    return 0;
}

// 预期输出：
// ptr is non-null
// nullPtr is null
