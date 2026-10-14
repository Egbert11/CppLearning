// 来源小节：11.10 Using function templates in multiple files
// 示例说明：foo.cpp 也 #include "max.h"，并为 max(3, 2) 实例化 max<int>
// 原文链接：https://www.learncpp.com/cpp-tutorial/using-function-templates-in-multiple-files/
// 本节代码为按原文描述重建

#include "max.h" // import template definition for max<T>(T, T)
#include <iostream>

void foo()
{
    std::cout << max(3, 2) << '\n';
}
