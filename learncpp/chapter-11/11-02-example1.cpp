// 来源小节：11.2 Function overload differentiation
// 示例说明：按参数"个数"重载——两个 add() 因参数个数不同而可区分。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-overload-differentiation/
//
// 编译：g++ -std=c++20 -Wall 11-02-example1.cpp -o a
//
// 本节代码为按原文描述重建。

#include <iostream>

int add(int x, int y)
{
    return x + y;
}

int add(int x, int y, int z)
{
    return x + y + z;
}

int main()
{
    std::cout << add(1, 2) << '\n';     // calls add(int, int) -> 3
    std::cout << add(1, 2, 3) << '\n';  // calls add(int, int, int) -> 6

    return 0;
}
