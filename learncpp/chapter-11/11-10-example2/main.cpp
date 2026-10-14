// 来源小节：11.10 Using function templates in multiple files
// 示例说明：包含 add.h 后即可正常实例化 addOne<int>/addOne<double>，程序可编译链接运行
// 原文链接：https://www.learncpp.com/cpp-tutorial/using-function-templates-in-multiple-files/
// 本节代码为按原文描述重建
// 预期输出：
// 2
// 3.3

#include "add.h" // import the function template definition
#include <iostream>

int main()
{
    std::cout << addOne(1) << '\n';
    std::cout << addOne(2.3) << '\n';

    return 0;
}
