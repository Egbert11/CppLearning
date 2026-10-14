// ============================================================
// 来源小节：12.3 Lvalue references
// 示例说明：测验——判断三行输出分别是什么。ref 始终绑定 x，
//           ref = y 只是把 y 的值（2）赋给 x，并未让 ref 改指 y；
//           之后 y = 3 只改 y。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lvalue-references/
// 备注：本节代码为按原文描述忠实重建（原 Example 11 / Quiz）。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x{ 1 };
    int& ref{ x };

    std::cout << x << ref << '\n'; // 11

    int y{ 2 };
    ref = y; // ref still bound to x; this copies 2 into x
    y = 3;   // only y changes

    std::cout << x << ref << '\n'; // 22

    x = 4;

    std::cout << x << ref << '\n'; // 44
    // --- 原文示例片段结束 ---

    return 0;
}

// 预期输出：
// 11
// 22
// 44
