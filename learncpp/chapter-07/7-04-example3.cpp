// 来源小节：7.4 Introduction to global variables
// 示例说明：非 const 全局变量的三种初始化写法——不写初始化式（默认零初始化）、值初始化、
//           带具体值的列表初始化。（对应原文 Example 3）
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-global-variables/
//
// 预期输出：0 0 1
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#include <iostream>

int g_x;       // no explicit initializer (zero-initialized by default)
int g_y {};    // value initialized (resulting in zero-initialization)
int g_z { 1 }; // list initialized with specific value

int main()
{
    std::cout << g_x << ' ' << g_y << ' ' << g_z << '\n';
    return 0;
}
