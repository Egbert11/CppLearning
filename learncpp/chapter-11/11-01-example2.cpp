// 来源小节：11.1 Introduction to function overloading
// 示例说明：两个同名 add() 重载共存（int 版与 double 版），由重载解析分别选出正确版本。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-function-overloading/
//
// 编译：g++ -std=c++20 -Wall 11-01-example2.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 原文预期输出：
//   3
//   4.6

#include <iostream>

int add(int x, int y) // integer version
{
    return x + y;
}

double add(double x, double y) // floating point version
{
    return x + y;
}

int main()
{
    std::cout << add(1, 2); // calls add(int, int)
    std::cout << '\n';
    std::cout << add(1.2, 3.4); // calls add(double, double)

    return 0;
}
