// 来源小节：7.8 Why (non-const) global variables are evil
// 示例说明：坏实践——把 gravity 放在全局命名空间，存在与其它同名全局变量冲突的风险。
//           应改用命名空间（见 7-08-example6.cpp）。（对应原文 Example 5）
// 原文链接：https://www.learncpp.com/cpp-tutorial/why-non-const-global-variables-are-evil/
//
// ※※※ 坏实践演示（-broken）※※※
// 本文件可正常编译运行，仅用于展示"全局命名空间中裸放常量"的隐患，请勿模仿。
//
// 预期输出：9.8

#include <iostream>

constexpr double gravity { 9.8 }; // risk of collision with some other global variable named gravity

int main()
{
    std::cout << gravity << '\n';
    return 0;
}
