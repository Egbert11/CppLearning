// 来源小节：11.4 Deleting functions
// 示例说明：形参为 int 的函数仍可被 char 与 bool 调用——它们会隐式提升为 97 与 1。
// 原文链接：https://www.learncpp.com/cpp-tutorial/deleting-functions/
//
// 编译：g++ -std=c++20 -Wall 11-04-example1.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 原文预期输出：
//   5
//   97
//   1

#include <iostream>

void printInt(int x)
{
    std::cout << x << '\n';
}

int main()
{
    printInt(5);    // okay: prints 5
    printInt('a');  // prints 97 -- does this make sense?
    printInt(true); // prints 1 -- does this make sense?

    return 0;
}
