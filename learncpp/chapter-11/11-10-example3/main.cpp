// 来源小节：11.10 Using function templates in multiple files
// 示例说明：main.cpp 与 foo.cpp 各自 #include "max.h"，都能实例化 max<int>；
//           隐式实例化出的函数是隐式 inline 的，两个文件中的同名实例定义相同，符合 ODR。
// 原文链接：https://www.learncpp.com/cpp-tutorial/using-function-templates-in-multiple-files/
// 本节代码为按原文描述重建
// 预期输出：
// 5
// 3

#include "max.h" // import template definition for max<T>(T, T)
#include <iostream>

void foo(); // forward declaration for function foo

int main()
{
    std::cout << max(3, 5) << '\n';
    foo();

    return 0;
}
