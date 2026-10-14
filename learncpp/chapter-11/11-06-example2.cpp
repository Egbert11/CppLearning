// 来源小节：11.6 Function templates
// 示例说明：为支持浮点再加一个 double 版 max 重载——函数体与 int 版完全相同。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-templates/
//
// 编译：g++ -std=c++20 -Wall 11-06-example2.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 预期输出：
//   2
//   2.5

#include <iostream>

int max(int x, int y)
{
    return (x < y) ? y : x;
}

double max(double x, double y)
{
    return (x < y) ? y: x;
}

int main()
{
    std::cout << max(1, 2) << '\n';     // calls max(int, int)
    std::cout << max(1.5, 2.5) << '\n'; // calls max(double, double)

    return 0;
}
