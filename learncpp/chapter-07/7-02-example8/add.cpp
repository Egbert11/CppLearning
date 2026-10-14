// 来源小节：7.2 User-defined namespaces and the scope resolution operator
// 示例说明：在 namespace BasicMath 内定义 add()（对应原文 Example 8 的 add.cpp）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/user-defined-namespaces-and-the-scope-resolution-operator/

#include "add.h"

namespace BasicMath
{
    // definition for function add()
    int add(int x, int y)
    {
        return x + y;
    }
}
