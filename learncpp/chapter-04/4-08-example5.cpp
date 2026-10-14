// 来源小节：4.8 Floating point numbers
// 示例说明：用 std::setprecision(17) 显示 float 与 double 的精度差异，
//          说明 float 携带的误差更大。
// 原文链接：https://www.learncpp.com/cpp-tutorial/floating-point-numbers/
// 预期输出（可能因编译器/平台略有差异）：
//   3.3333332538604736
//   3.3333333333333335
// 说明：本文件为重建代码。

#include <iomanip> // for std::setprecision()
#include <iostream>

int main()
{
    std::cout << std::setprecision(17); // show 17 digits of precision
    std::cout << 3.33333333333333333333333333333333333333f << '\n'; // f suffix means float
    std::cout << 3.33333333333333333333333333333333333333 << '\n';  // no suffix means double

    return 0;
}
