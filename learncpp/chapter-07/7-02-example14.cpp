// 来源小节：7.2 User-defined namespaces and the scope resolution operator
// 示例说明：重新指向别名——把 `Active` 从 Foo::Goo 改为 V2，原有 `Active::add(1, 2)` 调用无需改动。
//           （对应原文 Example 14）
// 原文链接：https://www.learncpp.com/cpp-tutorial/user-defined-namespaces-and-the-scope-resolution-operator/
//
// 预期输出：3
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#include <iostream>

namespace Foo::Goo { } // an empty namespace, e.g. the old implementation

namespace V2
{
    int add(int x, int y)
    {
        return x + y;
    }
}

int main()
{
    namespace Active = V2; // Now Active refers to V2

    std::cout << Active::add(1, 2) << '\n'; // The call site does not need to change

    return 0;
}
