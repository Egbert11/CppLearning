// 来源小节：2.1 Introduction to functions
// 示例说明：example4 的修正版 —— 把 foo() 移到 main() 外面，定义一个完整的用户自定义函数。
//           预期输出：foo!
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-functions/
//
// 编译：g++ -std=c++20 -Wall 2-01-example5.cpp -o a

#include <iostream>

void foo() // no longer inside of main()
{
    std::cout << "foo!\n";
}

int main()
{
    foo();

    return 0;
}
