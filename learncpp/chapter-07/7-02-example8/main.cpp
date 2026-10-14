// 来源小节：7.2 User-defined namespaces and the scope resolution operator
// 示例说明：用限定名调用定义在另一文件命名空间里的函数（对应原文 Example 8 的 main.cpp）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/user-defined-namespaces-and-the-scope-resolution-operator/
//
// 预期输出：7

#include <iostream>
#include "add.h" // for BasicMath::add()

int main()
{
    std::cout << BasicMath::add(4, 3) << '\n';

    return 0;
}
