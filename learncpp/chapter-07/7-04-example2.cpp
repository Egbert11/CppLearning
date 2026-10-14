// 来源小节：7.4 Introduction to global variables
// 示例说明：把同一个全局变量放进 Foo 命名空间。它仍是全局变量，只是名字限定在命名空间作用域里，
//           用限定名 Foo::g_x 访问。（对应原文 Example 2）
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-global-variables/
//
// 预期输出：
//   3
//   3
//   5
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#include <iostream>

namespace Foo // Foo is defined in the global scope
{
    int g_x {}; // g_x is now inside the Foo namespace, but is still a global variable
}

void doSomething()
{
    // global variables can be seen and used everywhere in the file
    Foo::g_x = 3;
    std::cout << Foo::g_x << '\n';
}

int main()
{
    doSomething();
    std::cout << Foo::g_x << '\n';

    // global variables can be seen and used everywhere in the file
    Foo::g_x = 5;
    std::cout << Foo::g_x << '\n';

    return 0;
}
