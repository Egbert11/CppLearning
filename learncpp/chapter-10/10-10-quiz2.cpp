// 来源小节：10.x Chapter 10 summary and quiz（本文件编号 10-10）
// 示例说明：测验 2a 解答——用类型别名 Degrees / Radians 重写度/弧度转换程序。
//           同时含测验 2b 的演示：radians = degrees; 可以编译（两个别名都是 double）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-10-summary-and-quiz/
//
// 编译：g++ -std=c++20 -Wall 10-10-quiz2.cpp -o a
// 示例交互（输入 180）：
//   Enter a number of degrees: 180
//   180 deg = 3.14159 rad
//   radians = degrees compiles: 180
//
// 本节代码为按原文解答要点重建。

#include <iostream>

namespace constants
{
    constexpr double pi{ 3.14159 };
}

// --- 原文示例片段（类型别名） ---
using Degrees = double;
using Radians = double;
// --- 原文示例片段结束 ---

Radians convertToRadians(Degrees degrees)
{
    return degrees * constants::pi / 180;
}

int main()
{
    std::cout << "Enter a number of degrees: ";
    Degrees degrees{};
    std::cin >> degrees;

    Radians radians{ convertToRadians(degrees) };
    std::cout << degrees << " deg = " << radians << " rad\n";

    // --- 原文示例片段（测验 2b：别名不构成类型区分，可以编译） ---
    radians = degrees; // compiles: Degrees 与 Radians 都是 double
    // --- 原文示例片段结束 ---
    std::cout << "radians = degrees compiles: " << radians << '\n';

    return 0;
}
