// ============================================================
// 来源小节：6.2 Arithmetic operators
// 示例说明：用 static_cast<> 对比整数除法与浮点除法；
//           只要有一个操作数是浮点，就做浮点除法。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arithmetic-operators/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    constexpr int x{ 7 };
    constexpr int y{ 4 };

    std::cout << "int / int = " << x / y << '\n';
    std::cout << "double / int = " << static_cast<double>(x) / y << '\n';
    std::cout << "int / double = " << x / static_cast<double>(y) << '\n';
    std::cout << "double / double = " << static_cast<double>(x) / static_cast<double>(y) << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
