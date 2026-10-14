// 来源小节：11.3 Function overload resolution and ambiguous matches
// 示例说明：步骤 2 数值提升——'a' 与 true 提升为 int，4.5f 提升为 double，从而解析到对应重载。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-overload-resolution-and-ambiguous-matches/
//
// 编译：g++ -std=c++20 -Wall 11-03-example5.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 预期输出：
//   foo(int)
//   foo(int)
//   foo(double)

#include <iostream>

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
    foo('a');   // 'a' promoted to match foo(int)
    foo(true);  // true promoted to match foo(int)
    foo(4.5f);  // 4.5f promoted to match foo(double)

    return 0;
}
