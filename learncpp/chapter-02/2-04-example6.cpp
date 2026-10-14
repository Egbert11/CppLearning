// 来源小节：2.4 Introduction to function parameters and arguments
// 示例说明：形参 x、y 通过拷贝初始化从实参 6、7 得到值。
//           预期输出：
//           6
//           7
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-function-parameters-and-arguments/
//
// 编译：g++ -std=c++20 -Wall 2-04-example6.cpp -o a

#include <iostream>

void printValues(int x, int y)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
}

int main()
{
    printValues(6, 7); // printValues() called with two arguments, 6 and 7

    return 0;
}
