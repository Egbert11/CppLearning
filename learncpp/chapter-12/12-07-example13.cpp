// ============================================================
// 来源小节：12.7 Introduction to pointers
// 示例说明：通过解引用赋值 *ptr = 6 改变"被指向的值"（即 x），而
//           不是改变指针本身。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/
// 备注：本节代码为按原文描述忠实重建（原 Example 13）。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x{ 5 };
    int* ptr{ &x };

    std::cout << x << ' ' << *ptr << '\n'; // 5 5

    *ptr = 6; // change the value being pointed at (x) to 6

    std::cout << x << ' ' << *ptr << '\n'; // 6 6
    // --- 原文示例片段结束 ---

    return 0;
}

// 预期输出：
// 5 5
// 6 6
