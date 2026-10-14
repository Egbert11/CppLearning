// 来源小节：7.8 Why (non-const) global variables are evil
// 示例说明：函数直接耦合到命名空间里的全局常量（较低复用性）——instantVelocity() 内部
//           硬编码使用 constants::gravity。（对应原文 Example 9）
// 原文链接：https://www.learncpp.com/cpp-tutorial/why-non-const-global-variables-are-evil/
//
// 预期输出：49
//
// ※ 本节示例为按原文描述重建，语义与原文一致。
//   与 7-08-example10.cpp 的"把 gravity 作为参数传入"版本对比。

#include <iostream>

namespace constants
{
    constexpr double gravity { 9.8 };
}

double instantVelocity(int time)
{
    return constants::gravity * time; // coupled to the global constant
}

int main()
{
    std::cout << instantVelocity(5) << '\n';
    return 0;
}
