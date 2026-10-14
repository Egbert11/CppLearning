// 来源小节：F.1 Constexpr functions
// 示例说明：把同样的计算搬进普通函数后无法用于常量表达式 —— 预期编译失败。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constexpr-functions/
//
// 预期错误：calcCircumference() 不是 constexpr 函数，因此
//   constexpr double circumference { calcCircumference(3.0) };
// 无法在编译期求值。g++ 报错类似：
//   error: call to non-'constexpr' function 'double calcCircumference(double)'
//   error: 'constexpr' variable ... is not a constant expression
//
// 说明：本文件为按原文描述重建，故意保留编译错误，请勿修复。
//       本文件预期编译失败。
#include <iostream>

double calcCircumference(double radius) // note: 不是 constexpr 函数
{
    constexpr double pi { 3.14159265359 };
    return 2.0 * pi * radius;
}

int main()
{
    constexpr double circumference { calcCircumference(3.0) }; // compile error

    std::cout << "Our circle has circumference " << circumference << "\n";

    return 0;
}
