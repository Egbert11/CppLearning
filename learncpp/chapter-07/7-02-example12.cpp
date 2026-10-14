// 来源小节：7.2 User-defined namespaces and the scope resolution operator
// 示例说明：C++17 嵌套写法 + 单独的 Foo 命名空间块。add 属于 Foo::Goo，subtract 只属于 Foo。
//           （对应原文 Example 12）
// 原文链接：https://www.learncpp.com/cpp-tutorial/user-defined-namespaces-and-the-scope-resolution-operator/
//
// 预期输出：
//   3
//   1
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#include <iostream>

namespace Foo::Goo // Goo is nested inside Foo
{
    int add(int x, int y)
    {
        return x + y;
    }
}

namespace Foo // adds to the Foo namespace (only, not Foo::Goo)
{
    int subtract(int x, int y)
    {
        return x - y;
    }
}

int main()
{
    std::cout << Foo::Goo::add(1, 2) << '\n';   // 3
    std::cout << Foo::subtract(4, 3) << '\n';   // 1
    return 0;
}
