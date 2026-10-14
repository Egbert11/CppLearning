// 来源小节：7.8 Why (non-const) global variables are evil
// 示例说明：用非常量初始化式（函数返回值）初始化全局变量，属于**动态初始化**（dynamic initialization）。
//           （对应原文 Example 3）
// 原文链接：https://www.learncpp.com/cpp-tutorial/why-non-const-global-variables-are-evil/
//
// 预期输出：5
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#include <iostream>

int init()
{
    return 5;
}

int g_something{ init() }; // non-constexpr initialization

int main()
{
    std::cout << g_something << '\n';
    return 0;
}
