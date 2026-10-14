// ============================================================
// 来源小节：6.6 The conditional operator
// 示例说明：修复上例错误的两种方式——
//           (1) 用 std::to_string 与 std::string 字面量做显式转换；
//           (2) 改用 if-else 语句。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-conditional-operator/
// 备注：本节代码为按原文描述忠实重建（x 故意不是 constexpr）。
// ============================================================
#include <iostream>
#include <string>

int main()
{
    // --- 原文示例片段 ---
    int x{ 5 };

    // Fix 1: convert explicitly to a common type (std::string)
    std::cout << ((x != 5) ? std::to_string(x) : std::string{ "x is 5" }) << '\n';

    // Fix 2: just use an if-else statement instead
    if (x != 5)
        std::cout << x << '\n';
    else
        std::cout << "x is 5\n";
    // --- 原文示例片段结束 ---

    return 0;
}
