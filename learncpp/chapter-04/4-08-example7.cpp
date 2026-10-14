// 来源小节：4.8 Floating point numbers
// 示例说明：double d{0.1} 在默认精度与 17 位精度下的不同输出，说明 0.1 无法被精确存储。
// 原文链接：https://www.learncpp.com/cpp-tutorial/floating-point-numbers/
// 预期输出：
//   0.1
//   0.10000000000000001
// 说明：本文件为重建代码。

#include <iomanip> // for std::setprecision()
#include <iostream>

int main()
{
    double d{0.1};
    std::cout << d << '\n';               // use default cout precision of 6
    std::cout << std::setprecision(17);
    std::cout << d << '\n';

    return 0;
}
