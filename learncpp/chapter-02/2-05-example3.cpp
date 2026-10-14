// 来源小节：2.5 Introduction to local scope
// 示例说明：生存期演示 —— main 中的 x 在调用 doSomething() 期间依然存活，
//           直到 main 结束的右花括号处才被销毁。
//           预期输出：Hello!
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-local-scope/
//
// 编译：g++ -std=c++20 -Wall 2-05-example3.cpp -o a

#include <iostream>

void doSomething()
{
    std::cout << "Hello!\n";
}

int main()
{
    int x{ 0 }; // x's lifetime begins here

    doSomething(); // x is still alive during this function call

    return 0;
} // x's lifetime ends here
