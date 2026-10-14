// 来源小节：11.1 Introduction to function overloading
// 示例说明：重载的"变通做法"——用两个不同名字的函数分别为 int 与 double 做加法。
//           能工作，但需要维护命名规范，并记住哪个名字对应哪种类型。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-function-overloading/
//
// 编译：g++ -std=c++20 -Wall 11-01-example1.cpp -o a
//
// 本节代码为按原文描述重建。

#include <iostream>

int addInteger(int x, int y)
{
    return x + y;
}

double addDouble(double x, double y)
{
    return x + y;
}

int main()
{
    std::cout << addInteger(1, 2) << '\n';     // 3
    std::cout << addDouble(1.2, 3.4) << '\n';  // 4.6

    return 0;
}
