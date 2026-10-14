// 来源小节：F.1 Constexpr functions
// 示例说明：用 constexpr 变量在编译期计算圆周长。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constexpr-functions/
//
// 预期输出：
//   Our circle has circumference 18.8496
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块），语义与预期输出一致。
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    constexpr double radius { 3.0 };
    constexpr double pi { 3.14159265359 };
    constexpr double circumference { 2.0 * radius * pi };

    std::cout << "Our circle has circumference " << circumference << "\n";
    // --- 原文示例片段结束 ---

    return 0;
}
