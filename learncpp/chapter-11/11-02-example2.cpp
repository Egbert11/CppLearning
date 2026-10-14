// 来源小节：11.2 Function overload differentiation
// 示例说明：按参数"类型列表"重载——四个 add() 的参数类型列表互不相同，均可区分。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-overload-differentiation/
//
// 编译：g++ -std=c++20 -Wall 11-02-example2.cpp -o a
//
// 本节代码为按原文描述重建（原文只列出声明，这里补上定义与调用以便编译运行）。

#include <iostream>

int add(int x, int y); // integer version
double add(double x, double y); // floating point version
double add(int x, double y); // mixed version
double add(double x, int y); // mixed version

int add(int x, int y)
{
    return x + y;
}

double add(double x, double y)
{
    return x + y;
}

double add(int x, double y)
{
    return x + y;
}

double add(double x, int y)
{
    return x + y;
}

int main()
{
    std::cout << add(1, 2) << '\n';       // add(int, int)
    std::cout << add(1.5, 2.5) << '\n';   // add(double, double)
    std::cout << add(1, 2.5) << '\n';     // add(int, double)
    std::cout << add(1.5, 2) << '\n';     // add(double, int)

    return 0;
}
