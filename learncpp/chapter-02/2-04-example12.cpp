// 来源小节：2.4 Introduction to function parameters and arguments
// 示例说明：未命名参数 —— 定义中省略参数名即可避免未使用参数的警告；
//           Google C++ 风格指南建议把省略的名字写在注释中。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-function-parameters-and-arguments/
//
// 编译：g++ -std=c++20 -Wall 2-04-example12.cpp -o a

#include <iostream>

void doSomething(int) // ok: unnamed parameter will not generate warning
{
}

// Google C++ style guide recommends this form: the omitted name is kept in a comment
void doSomethingElse(int /* count */)
{
}

int main()
{
    doSomething(5);
    doSomethingElse(3);

    return 0;
}
