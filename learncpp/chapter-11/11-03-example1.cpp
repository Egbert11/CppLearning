// 来源小节：11.3 Function overload resolution and ambiguous matches
// 示例说明：步骤 1 精确匹配——int 实参精确匹配 print(int)，double 实参精确匹配 print(double)。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-overload-resolution-and-ambiguous-matches/
//
// 编译：g++ -std=c++20 -Wall 11-03-example1.cpp -o a
//
// 本节代码为按原文描述重建。

#include <iostream>

void print(int x)
{
    std::cout << "print(int): " << x << '\n';
}

void print(double d)
{
    std::cout << "print(double): " << d << '\n';
}

int main()
{
    print(5);   // 5 is an int, so this matches print(int)
    print(6.7); // 6.7 is a double, so this matches print(double)

    return 0;
}
