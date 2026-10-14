// 来源小节：7.8 Why (non-const) global variables are evil
// 示例说明：调试全局变量取到意外值的情形——某函数以为 g_mode == 4，实际却是 3；
//           要找出真相，必须检查每一处对 g_mode 的赋值。（对应原文 Example 2）
// 原文链接：https://www.learncpp.com/cpp-tutorial/why-non-const-global-variables-are-evil/
//
// 预期输出：g_mode is 3, not 4 -- debugging required
//
// ※ 本节示例为按原文描述重建，语义与原文一致（原示例为一小段片段）。

#include <iostream>

int g_mode { 3 }; // some other code set g_mode to 3 somewhere

void someFunction()
{
    if (g_mode == 4) // programmer expects g_mode to be 4 here, but it's actually 3
        std::cout << "Doing something special\n";
    else
        std::cout << "g_mode is 3, not 4 -- debugging required\n";
}

int main()
{
    someFunction();
    return 0;
}
