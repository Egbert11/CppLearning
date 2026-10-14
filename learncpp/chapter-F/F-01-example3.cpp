// 来源小节：F.1 Constexpr functions
// 示例说明：把函数标记为 constexpr 后即可用于常量表达式，编译通过。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constexpr-functions/
//
// 预期输出：
//   Our circle has circumference 18.8496
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块），语义与预期输出一致。
#include <iostream>

constexpr double calcCircumference(double radius) // now a constexpr function
{
    constexpr double pi { 3.14159265359 };
    return 2.0 * pi * radius;
}

int main()
{
    // --- 原文示例片段 ---
    constexpr double circumference { calcCircumference(3.0) }; // now compiles

    std::cout << "Our circle has circumference " << circumference << "\n";
    // --- 原文示例片段结束 ---

    return 0;
}
