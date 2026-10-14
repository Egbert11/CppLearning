// 来源小节：7.8 Why (non-const) global variables are evil
// 示例说明：同一文件内的初始化顺序问题——g_x 在 g_y 之前初始化，而 initX() 返回 g_y，
//           此时 g_y 尚未（动态）初始化，仍为零初始化值 0。（对应原文 Example 4）
// 原文链接：https://www.learncpp.com/cpp-tutorial/why-non-const-global-variables-are-evil/
//
// 预期输出：0 5
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#include <iostream>

int initX(); // forward declaration
int initY(); // forward declaration

int g_x{ initX() }; // g_x is initialized first
int g_y{ initY() };

int initX()
{
    return g_y; // g_y isn't initialized when this is called
}

int initY()
{
    return 5;
}

int main()
{
    std::cout << g_x << ' ' << g_y << '\n';
    return 0;
}
