// ============================================================
// 来源小节：6.2 Arithmetic operators
// 示例说明：浮点除法除以用户输入值。d 为 double，故为浮点除法。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arithmetic-operators/
// 备注：本节代码为按原文描述忠实重建。
//       可尝试输入 0 或 0.0 观察结果（IEEE754 上为 NaN 或 Inf）。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    constexpr int apples { 12 };
    std::cout << "How many servings do you want to divide " << apples << " apples into? ";
    double d {};
    std::cin >> d;

    // d is a double, so this is floating point division
    std::cout << "Each serving gets " << apples / d << " apples.\n";
    // --- 原文示例片段结束 ---

    return 0;
}
