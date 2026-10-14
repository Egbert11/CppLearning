// 来源小节：2.4 Introduction to function parameters and arguments
// 示例说明：实参可以是任意表达式，也可以是另一个函数调用的返回值；嵌套调用时内层先求值。
//           预期输出：
//           9
//           15
//           10
//           7
//           6
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-function-parameters-and-arguments/
//
// 编译：g++ -std=c++20 -Wall 2-04-example10.cpp -o a

#include <iostream>

int add(int x, int y)
{
    return x + y;
}

int multiply(int z, int w)
{
    return z * w;
}

int main()
{
    std::cout << add(4, 5) << '\n';           // within add() x=4, y=5, so x+y=9
    std::cout << add(1 + 2, 3 * 4) << '\n';   // within add() x=3, y=12, so x+y=15

    int a{ 5 };
    std::cout << add(a, a) << '\n';           // evaluates (5 + 5)

    std::cout << add(1, multiply(2, 3)) << '\n'; // evaluates 1 + (2 * 3)
    std::cout << add(1, add(2, 3)) << '\n';      // evaluates 1 + (2 + 3)

    return 0;
}
