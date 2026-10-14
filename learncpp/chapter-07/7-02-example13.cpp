// 来源小节：7.2 User-defined namespaces and the scope resolution operator
// 示例说明：命名空间别名——用 `namespace Active = Foo::Goo;` 缩短长限定路径，别名在其作用域结束时失效。
//           （对应原文 Example 13）
// 原文链接：https://www.learncpp.com/cpp-tutorial/user-defined-namespaces-and-the-scope-resolution-operator/
//
// 预期输出：3
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#include <iostream>

namespace Foo::Goo
{
    int add(int x, int y)
    {
        return x + y;
    }
}

int main()
{
    namespace Active = Foo::Goo; // active now refers to Foo::Goo

    std::cout << Active::add(1, 2) << '\n'; // We don't have to use Foo::Goo::add()

    return 0; // The Active alias ends here
}
