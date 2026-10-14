// 来源小节：7.8 Why (non-const) global variables are evil
// 示例说明：非 const 全局变量 g_mode 被另一个函数悄悄改成 2，而 main 仍以为它是 1——
//           演示全局变量带来的"不可预测状态"。（对应原文 Example 1）
// 原文链接：https://www.learncpp.com/cpp-tutorial/why-non-const-global-variables-are-evil/
//
// 预期输出：Launching nuclear missiles...
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#include <iostream>

int g_mode; // declare global variable (will be zero-initialized by default)

void doSomething()
{
    g_mode = 2; // set the global g_mode variable to 2
}

int main()
{
    g_mode = 1; // note: this sets the global g_mode variable to 1.  It does not declare a local g_mode variable!

    doSomething(); // programmer thought that g_mode would still be 1

    // Programmer still expects g_mode to be 1
    // But doSomething changed it to 2!

    if (g_mode == 1)
        std::cout << "No threat detected.\n";
    else
        std::cout << "Launching nuclear missiles...\n";

    return 0;
}
