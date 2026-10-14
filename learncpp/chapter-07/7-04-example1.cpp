// 来源小节：7.4 Introduction to global variables
// 示例说明：在全局命名空间定义全局变量 g_x，两个函数都能看到并使用它。（对应原文 Example 1）
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-global-variables/
//
// 预期输出：
//   3
//   3
//   5
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#include <iostream>

// Variables declared outside of a function are global variables
int g_x {}; // global variable g_x

void doSomething()
{
    // global variables can be seen and used everywhere in the file
    g_x = 3;
    std::cout << g_x << '\n';
}

int main()
{
    doSomething();
    std::cout << g_x << '\n';

    // global variables can be seen and used everywhere in the file
    g_x = 5;
    std::cout << g_x << '\n';

    return 0;
}
// g_x goes out of scope here
