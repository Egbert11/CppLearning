// 来源小节：2.3 Void functions (non-value returning functions)
// 示例说明：最基本的 void 函数 printHi()：打印 "Hi"，无需 return 语句。
//           预期输出：Hi
// 原文链接：https://www.learncpp.com/cpp-tutorial/void-functions-non-value-returning-functions/
//
// 编译：g++ -std=c++20 -Wall 2-03-example1.cpp -o a

#include <iostream>

// void means the function does not return a value to the caller
void printHi()
{
    std::cout << "Hi" << '\n';

    // This function does not return a value so no return statement is needed
}

int main()
{
    printHi(); // okay: function return value is void (no value is returned)

    return 0;
}
