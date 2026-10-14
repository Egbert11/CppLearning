// 来源小节：7.8 Why (non-const) global variables are evil
// 示例说明：直接外部访问常量的 main（对应原文 Example 7 的 main.cpp）。可与 7-08-example8/ 的
//           "封装式访问"对比：这里直接依赖常量本身。（对应原文 Example 7）
// 原文链接：https://www.learncpp.com/cpp-tutorial/why-non-const-global-variables-are-evil/
//
// 预期输出：9.8

#include <iostream>

extern const double gravity; // forward declaration

int main()
{
    std::cout << gravity << '\n';
    return 0;
}
