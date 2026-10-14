// 来源小节：10.7 Typedefs and type aliases
// 示例说明：包含定义了 Miles/Speed 别名的头文件，并在本文件里使用它们。
//           （对应原文示例 6）
// 原文链接：https://www.learncpp.com/cpp-tutorial/typedefs-and-type-aliases/
//
// 编译：g++ -std=c++20 -Wall 10-07-example3/*.cpp -o a
//
// 本节代码为按原文描述重建。

#include <iostream>

#include "mytypes.h"

int main()
{
    Miles distance{ 100 };
    Speed velocity{ 60 };

    std::cout << distance << ' ' << velocity << '\n';

    return 0;
}
