// 来源小节：7.8 Why (non-const) global variables are evil
// 示例说明：把 gravity 作为参数传入函数（更高复用性、保持模块化，也能便于改变取值）——
//           与 7-08-example9.cpp 的硬编码版本对比。（对应原文 Example 10）
// 原文链接：https://www.learncpp.com/cpp-tutorial/why-non-const-global-variables-are-evil/
//
// 预期输出：49
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#include <iostream>

namespace constants
{
    constexpr double gravity { 9.8 };
}

double instantVelocity(int time, double gravity)
{
    return gravity * time;
}

int main()
{
    std::cout << instantVelocity(5, constants::gravity) << '\n';
    return 0;
}
