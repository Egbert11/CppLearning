// 来源小节：11.3 Function overload resolution and ambiguous matches
// 示例说明：步骤 4 用户定义转换——类 X 经 operator int() 把对象转换为 int，匹配 foo(int)。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-overload-resolution-and-ambiguous-matches/
//
// 编译：g++ -std=c++20 -Wall 11-03-example7.cpp -o a
//
// 本节代码为按原文描述重建。

#include <iostream>

class X
{
public:
    operator int() { return 0; } // user-defined conversion from X to int
};

void foo(int)
{
    std::cout << "foo(int)\n";
}

void foo(double)
{
    std::cout << "foo(double)\n";
}

int main()
{
    X x;
    foo(x); // x is converted to type int using the user-defined conversion, matches foo(int)

    return 0;
}
