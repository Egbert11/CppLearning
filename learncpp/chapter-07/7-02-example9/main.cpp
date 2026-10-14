// 来源小节：7.2 User-defined namespaces and the scope resolution operator
// 示例说明：同时使用来自两个头文件、但同属 BasicMath 命名空间的常量 pi 与 e。
//           （对应原文 Example 9 的 main.cpp）
// 原文链接：https://www.learncpp.com/cpp-tutorial/user-defined-namespaces-and-the-scope-resolution-operator/
//
// 预期输出：
//   3.14
//   2.7

#include <iostream>
#include "circle.h" // for BasicMath::pi
#include "growth.h" // for BasicMath::e

int main()
{
    std::cout << BasicMath::pi << '\n';
    std::cout << BasicMath::e << '\n';

    return 0;
}
