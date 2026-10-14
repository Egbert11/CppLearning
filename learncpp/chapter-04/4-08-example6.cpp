// 来源小节：4.8 Floating point numbers
// 示例说明：一个有效数字很多的 float（123456789.0f）无法精确存储，是舍入误差的例子。
// 原文链接：https://www.learncpp.com/cpp-tutorial/floating-point-numbers/
// 预期输出：123456792
// 说明：本文件为重建代码。

#include <iomanip> // for std::setprecision()
#include <iostream>

int main()
{
    float f { 123456789.0f };          // f has 10 significant digits
    std::cout << std::setprecision(9); // to show 9 digits in f
    std::cout << f << '\n';

    return 0;
}
