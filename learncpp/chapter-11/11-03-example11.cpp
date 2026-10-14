// 来源小节：11.3 Function overload resolution and ambiguous matches
// 示例说明：消除歧义的两种办法——显式 static_cast，或给字面量加类型后缀（u）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-overload-resolution-and-ambiguous-matches/
//
// 编译：g++ -std=c++20 -Wall 11-03-example11.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 预期输出：
//   foo(unsigned int)
//   foo(unsigned int)

#include <iostream>

void foo(unsigned int)
{
    std::cout << "foo(unsigned int)\n";
}

void foo(float)
{
    std::cout << "foo(float)\n";
}

int main()
{
    int x { 0 };

    foo(static_cast<unsigned int>(x)); // will call foo(unsigned int)
    foo(0u); // 0u has type unsigned int, so this is now an exact match

    return 0;
}
