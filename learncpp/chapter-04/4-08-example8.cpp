// 来源小节：4.8 Floating point numbers
// 示例说明：把 0.1 累加十次得到的和并不等于 1.0，说明不要直接比较浮点数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/floating-point-numbers/
// 预期输出（可能因编译器/平台略有差异）：
//   1
//   0.99999999999999989
// 说明：本文件为重建代码。

#include <iomanip> // for std::setprecision()
#include <iostream>

int main()
{
    std::cout << std::setprecision(17);

    double d1{ 1.0 };
    std::cout << d1 << '\n';

    double d2{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 };
    std::cout << d2 << '\n';

    return 0;
}
