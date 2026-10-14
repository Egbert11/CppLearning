// 来源小节：2.4 Introduction to function parameters and arguments
// 示例说明：add(4, 5) 把实参 4、5 传给形参 x、y，返回 9 并用 std::cout 打印。
//           预期输出：9
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-function-parameters-and-arguments/
//
// 编译：g++ -std=c++20 -Wall 2-04-example9.cpp -o a

#include <iostream>

int add(int x, int y) // function parameters x and y are local variables
{
    return x + y;
}

int main()
{
    std::cout << add(4, 5) << '\n'; // Arguments 4 and 5 are passed to function add

    return 0;
}
