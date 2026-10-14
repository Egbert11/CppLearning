// 来源小节：11.5 Default arguments
// 示例说明：把默认实参放在头文件的前向声明里，定义处不再重复。多文件示例（Example 10）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/default-arguments/
//
// 编译：g++ -std=c++20 -Wall 11-05-example8/*.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 预期输出：
//   x: 5
//   y: 4

#include "foo.h"
#include <iostream>

void print(int x, int y)
{
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}

int main()
{
    print(5);

    return 0;
}
