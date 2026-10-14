// 来源小节：7.2 User-defined namespaces and the scope resolution operator
// 示例说明：命名空间内部的非限定名查找——Foo::printHelloThere() 里的 print() 先在当前
//           命名空间（Foo）里查找，因此解析为 Foo::print()；::print() 则显式指定全局版本。
//           （对应原文 Example 7）
// 原文链接：https://www.learncpp.com/cpp-tutorial/user-defined-namespaces-and-the-scope-resolution-operator/
//
// 预期输出：Hello there
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#include <iostream>

void print() // this print() lives in the global namespace
{
    std::cout << " there\n";
}

namespace Foo
{
    void print() // this print() lives in the Foo namespace
    {
        std::cout << "Hello";
    }

    void printHelloThere()
    {
        print();   // calls Foo::print(), since unqualified lookup finds the current namespace first
        ::print(); // calls the global print()
    }
}

int main()
{
    Foo::printHelloThere();
    return 0;
}
