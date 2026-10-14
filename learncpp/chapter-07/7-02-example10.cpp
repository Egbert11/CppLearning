// 来源小节：7.2 User-defined namespaces and the scope resolution operator
// 示例说明：嵌套命名空间——Goo 定义在 Foo 内部，函数用 Foo::Goo::add 访问。（对应原文 Example 10）
// 原文链接：https://www.learncpp.com/cpp-tutorial/user-defined-namespaces-and-the-scope-resolution-operator/
//
// 预期输出：3
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#include <iostream>

namespace Foo
{
    namespace Goo // Goo is a namespace inside the Foo namespace
    {
        int add(int x, int y)
        {
            return x + y;
        }
    }
}

int main()
{
    std::cout << Foo::Goo::add(1, 2) << '\n';
    return 0;
}
