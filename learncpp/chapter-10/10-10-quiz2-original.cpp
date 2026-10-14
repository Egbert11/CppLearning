// 来源小节：10.x Chapter 10 summary and quiz（本文件编号 10-10）
// 示例说明：测验 2a 的起始程序（未使用类型别名）——把角度转换为弧度。
//           后续在 10-10-quiz2.cpp 中用类型别名重写。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-10-summary-and-quiz/
//
// 编译：g++ -std=c++20 -Wall 10-10-quiz2-original.cpp -o a
// 示例交互（输入 180）：
//   Enter a number of degrees: 180
//   180 deg = 3.14159 rad
//
// 本节代码为按原文解答要点重建。

#include <iostream>

namespace constants
{
    constexpr double pi{ 3.14159 };
}

double convertToRadians(double degrees)
{
    return degrees * constants::pi / 180;
}

int main()
{
    std::cout << "Enter a number of degrees: ";
    double degrees{};
    std::cin >> degrees;

    double radians{ convertToRadians(degrees) };
    std::cout << degrees << " deg = " << radians << " rad\n";

    return 0;
}
