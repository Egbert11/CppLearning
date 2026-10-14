// ============================================================
// 来源小节：6.7 Relational operators and floating point comparisons
// 示例说明：相等判断失败——计算得到的值与字面量比较，输出 false。
// 原文链接：https://www.learncpp.com/cpp-tutorial/relational-operators-and-floating-point-comparisons/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::cout << std::boolalpha << (0.3 == 0.2 + 0.1); // prints false
    std::cout << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
