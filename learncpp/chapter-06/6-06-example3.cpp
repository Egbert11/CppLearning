// ============================================================
// 来源小节：6.6 The conditional operator
// 示例说明：条件运算符用于 constexpr 初始化——这是 if-else 无法直接做到的。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-conditional-operator/
// 备注：本节代码为按原文描述忠实重建。输出：The class size is: 20
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    constexpr bool inBigClassroom { false };
    constexpr int classSize { inBigClassroom ? 30 : 20 };

    std::cout << "The class size is: " << classSize << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
