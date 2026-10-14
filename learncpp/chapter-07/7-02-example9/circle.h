// 来源小节：7.2 User-defined namespaces and the scope resolution operator
// 示例说明：把常量 pi 放进 BasicMath 命名空间（对应原文 Example 9 的 circle.h）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/user-defined-namespaces-and-the-scope-resolution-operator/

#ifndef CIRCLE_H
#define CIRCLE_H

namespace BasicMath
{
    constexpr double pi{ 3.14 }; // The constant PI is part of the BasicMath namespace
}

#endif
