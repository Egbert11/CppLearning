// 来源小节：9.4 Detecting and handling errors
// 示例说明：即使出错也必须返回一个 double 的函数——reciprocal() 计算 x 的倒数 1/x；
//           reciprocal(0.0) 会崩溃（这里仅作展示，未做处理）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/detecting-and-handling-errors/
//
// 编译：g++ -std=c++20 -Wall 9-04-example5.cpp -o a
//
// 本节代码为按原文描述重建。

#include <iostream>

// The reciprocal of x is 1/x
double reciprocal(double x)
{
    return 1.0 / x; // reciprocal(0.0) would crash / produce inf
}

int main()
{
    std::cout << reciprocal(2.0) << '\n';

    return 0;
}
