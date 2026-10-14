// 来源小节：7.2 User-defined namespaces and the scope resolution operator
// 示例说明：依次用限定名调用 Foo 与 Goo 两个版本的同名函数，展示命名空间如何消除歧义。
//           （对应原文 Example 5）
// 原文链接：https://www.learncpp.com/cpp-tutorial/user-defined-namespaces-and-the-scope-resolution-operator/
//
// 预期输出：
//   7
//   1
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
    std::cout << Foo::doSomething(4, 3) << '\n'; // calls Foo::doSomething(), prints 7
    std::cout << Goo::doSomething(4, 3) << '\n'; // calls Goo::doSomething(), prints 1
    return 0;
}
