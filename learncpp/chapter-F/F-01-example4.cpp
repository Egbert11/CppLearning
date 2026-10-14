// 来源小节：F.1 Constexpr functions
// 示例说明：编译器在编译期求值后，实际上把函数调用替换成了它的返回值（概念性展示）。
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
    // The compiler essentially evaluates the constexpr function call and
    // replaces it with the resulting value (conceptually):
    constexpr double circumference { 18.8496 };

    std::cout << "Our circle has circumference " << circumference << "\n";
    // --- 原文示例片段结束 ---

    return 0;
}
