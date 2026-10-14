// 来源小节：11.3 Function overload resolution and ambiguous matches
// 示例说明：步骤 3 数值转换——没有精确/提升匹配时，'a' 经数值转换匹配到 foo(double)。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-overload-resolution-and-ambiguous-matches/
//
// 编译：g++ -std=c++20 -Wall 11-03-example6.cpp -o a
//
// 本节代码为按原文描述重建。
// 说明：'a' 到 double 是数值转换（步骤 3），到 std::string 是用户定义转换（步骤 4），
//       步骤 3 先于步骤 4，故选中 foo(double)。

#include <iostream>
#include <string>

void foo(double)
{
    std::cout << "foo(double)\n";
}

void foo(std::string)
{
    std::cout << "foo(std::string)\n";
}

int main()
{
    foo('a'); // 'a' converted to match foo(double)

    return 0;
}
