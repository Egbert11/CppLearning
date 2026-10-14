// 来源小节：7.2 User-defined namespaces and the scope resolution operator
// 示例说明：作用域解析运算符 :: 前缀为空时，表示在全局命名空间中查找。
//           Foo::print() 调用 Foo 里的版本，::print() 调用全局版本。（对应原文 Example 6）
// 原文链接：https://www.learncpp.com/cpp-tutorial/user-defined-namespaces-and-the-scope-resolution-operator/
//
// 预期输出：Hello there
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#include <iostream>

namespace Foo
{
    void print() // this print() lives in the Foo namespace
    {
        std::cout << "Hello";
    }
}

void print() // this print() lives in the global namespace
{
    std::cout << " there\n";
}

int main()
{
    Foo::print(); // Call print() in Foo namespace
    ::print();    // Call print() in global namespace (same as calling print() in this case)

    return 0;
}
