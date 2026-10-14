// ============================================================
// 来源小节：17.1 Introduction to std::array
// 示例说明：Quiz #2 解答——声明一个能保存一年 365 天每日最高气温的
//           std::array<double, 365>。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdarray/
// 预期输出：365
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <array>
#include <iostream>

int main()
{
    std::array<double, 365> highTemp {}; // daily high temperature for each day of the year

    std::cout << highTemp.size() << '\n';

    return 0;
}
