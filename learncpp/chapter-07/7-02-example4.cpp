// 来源小节：7.2 User-defined namespaces and the scope resolution operator
// 示例说明：与 Example 3 结构相同，但改用限定名 Goo::doSomething 调用 Goo 版本。
//           （对应原文 Example 4）
// 原文链接：https://www.learncpp.com/cpp-tutorial/user-defined-namespaces-and-the-scope-resolution-operator/
//
// 预期输出：1
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#include <iostream>

namespace Foo
{
    int doSomething(int x, int y)
    {
        return x + y;
    }
}

namespace Goo
{
    int doSomething(int x, int y)
    {
        return x - y;
    }
}

int main()
{
    std::cout << Goo::doSomething(4, 3) << '\n'; // calls Goo::doSomething()
    return 0;
}
