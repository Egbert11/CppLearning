// 来源小节：7.2 User-defined namespaces and the scope resolution operator
// 示例说明：C++17 起可用 `namespace Foo::Goo` 直接声明嵌套命名空间，等价于 Example 10 的写法。
//           （对应原文 Example 11）
// 原文链接：https://www.learncpp.com/cpp-tutorial/user-defined-namespaces-and-the-scope-resolution-operator/
//
// 预期输出：3
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#include <iostream>

namespace Foo::Goo // C++17: this declares a nested namespace Goo inside Foo
{
    int add(int x, int y)
    {
        return x + y;
    }
}

int main()
{
    std::cout << Foo::Goo::add(1, 2) << '\n';
    return 0;
}
