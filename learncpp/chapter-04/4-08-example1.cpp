// 来源小节：4.8 Floating point numbers
// 示例说明：检查 float / double / long double 是否兼容 IEEE 754（is_iec559）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/floating-point-numbers/
// 说明：本文件为重建代码。

#include <iostream>
#include <limits> // for std::numeric_limits

int main()
{
    std::cout << std::boolalpha; // print bools as true or false

    std::cout << "float: " << std::numeric_limits<float>::is_iec559 << '\n';
    std::cout << "double: " << std::numeric_limits<double>::is_iec559 << '\n';
    std::cout << "long double: " << std::numeric_limits<long double>::is_iec559 << '\n';

    return 0;
}
