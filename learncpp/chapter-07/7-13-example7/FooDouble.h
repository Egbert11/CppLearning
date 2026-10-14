// 来源小节：7.13 Using declarations and using directives
// 示例说明：提供 Foo::print(double) 的库头文件。
// 原文链接：https://www.learncpp.com/cpp-tutorial/using-declarations-and-using-directives/
//
// 本节示例为按原文描述重建（对应原文 Example 11 所用头文件的定义）。

#ifndef FOO_DOUBLE_H
#define FOO_DOUBLE_H

#include <iostream>

namespace Foo
{
    inline void print(double) { std::cout << "Foo::print(double)\n"; }
}

#endif
