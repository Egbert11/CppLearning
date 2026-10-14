// 来源小节：7.8 Why (non-const) global variables are evil
// 示例说明：只前向声明并调用 getGravity()，不直接依赖常量本身（对应原文 Example 8 的 main.cpp）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/why-non-const-global-variables-are-evil/
//
// 预期输出：9.8

#include <iostream>

double getGravity(); // forward declaration (has external linkage)

int main()
{
    std::cout << getGravity() << '\n';
    return 0;
}
