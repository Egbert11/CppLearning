// ============================================================
// 来源小节：6.4 Increment/decrement operators, and side effects
// 示例说明：前缀与后缀并排对比。前缀的变化在同一条输出语句中立即可见，
//           后缀的变化要到下一条输出语句才出现。
// 原文链接：https://www.learncpp.com/cpp-tutorial/increment-decrement-operators-and-side-effects/
// 备注：本节代码为按原文描述忠实重建。
//   输出：
//     5 5
//     6 4
//     6 4
//     6 4
//     7 3
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x { 5 };
    int y { 5 };

    std::cout << x << ' ' << y << '\n';
    std::cout << ++x << ' ' << --y << '\n'; // prefix
    std::cout << x << ' ' << y << '\n';
    std::cout << x++ << ' ' << y-- << '\n'; // postfix
    std::cout << x << ' ' << y << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
