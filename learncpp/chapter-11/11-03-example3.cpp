// 来源小节：11.3 Function overload resolution and ambiguous matches
// 示例说明：平凡转换——int 到 const int、double 到 const double& 都不改变值，仍算精确匹配。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-overload-resolution-and-ambiguous-matches/
//
// 编译：g++ -std=c++20 -Wall 11-03-example3.cpp -o a
//
// 本节代码为按原文描述重建。

#include <iostream>

void foo(const int)
{
    std::cout << "foo(const int)\n";
}

void foo(const double&)
{
    std::cout << "foo(const double&)\n";
}

int main()
{
    int x { 1 };
    foo(x); // x trivially converted from int to const int

    double d { 2.3 };
    foo(d); // d trivially converted from double to const double&

    return 0;
}
