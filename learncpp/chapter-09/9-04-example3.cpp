// 来源小节：9.4 Detecting and handling errors
// 示例说明：有返回值的函数无法简单"跳过"逻辑——doIntDivision() 必须返回一个 int，
//           因此除零成了一个真实风险（这里仅作展示，未做处理）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/detecting-and-handling-errors/
//
// 编译：g++ -std=c++20 -Wall 9-04-example3.cpp -o a
//
// 本节代码为按原文描述重建。

#include <iostream>

int doIntDivision(int x, int y) // ill-formed if y is zero
{
    return x / y;
}

int main()
{
    std::cout << doIntDivision(10, 2) << '\n';

    return 0;
}
