// 来源小节：11.2 Function overload differentiation
// 示例说明：省略号（ellipsis）算作一种独立的参数类型，故 foo(int,int) 与 foo(int,...) 可区分；
//           用两个 int 调用会绑定到精确匹配的 foo(int,int)。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-overload-differentiation/
//
// 编译：g++ -std=c++20 -Wall 11-02-example5.cpp -o a
//
// 本节代码为按原文描述重建。

#include <iostream>

void foo(int x, int y)
{
    std::cout << "foo(int, int) called with " << x << ", " << y << '\n';
}

void foo(int x, ...)
{
    std::cout << "foo(int, ...) called with first arg " << x << '\n';
}

int main()
{
    foo(4, 5); // matches foo(int, int), not foo(int, ...)

    return 0;
}
