// 来源小节：7.2 User-defined namespaces and the scope resolution operator
// 示例说明：把同名函数 doSomething() 分别放进 Foo 与 Goo 命名空间，用限定名 Foo::doSomething 调用 Foo 版本。
//           （对应原文 Example 3）
// 原文链接：https://www.learncpp.com/cpp-tutorial/user-defined-namespaces-and-the-scope-resolution-operator/
//
// 预期输出：7
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#include <iostream>

namespace Foo // Foo is defined in the global scope
{
    // doSomething() lives in namespace Foo
    int doSomething(int x, int y)
    {
        return x + y;
    }
}

namespace Goo // Goo is defined in the global scope
{
    // doSomething() lives in namespace Goo
    int doSomething(int x, int y)
    {
        return x - y;
    }
}

int main()
{
    std::cout << Foo::doSomething(4, 3) << '\n'; // calls Foo::doSomething()
    return 0;
}
