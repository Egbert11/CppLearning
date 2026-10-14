// 来源小节：2.4 Introduction to function parameters and arguments
// 示例说明：Quiz #3 —— 嵌套调用：内层的 add(1, 2, 3) 先求出 6，
//           再作为实参传给 multiply(6, 4)，结果为 24。
//           预期输出：24
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-function-parameters-and-arguments/
//
// 编译：g++ -std=c++20 -Wall 2-04-quiz3.cpp -o a

#include <iostream>

int add(int x, int y, int z)
{
    return x + y + z;
}

int multiply(int a, int b)
{
    return a * b;
}

int main()
{
    std::cout << multiply(add(1, 2, 3), 4) << '\n'; // 24

    return 0;
}
