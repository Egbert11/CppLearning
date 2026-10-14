// 来源小节：2.3 Void functions (non-value returning functions)
// 示例说明：Quiz 1a —— printA() 和 printB() 各自打印一个字母，两个都在 main 中被调用。
//           预期输出：
//           A
//           B
// 原文链接：https://www.learncpp.com/cpp-tutorial/void-functions-non-value-returning-functions/
//
// 编译：g++ -std=c++20 -Wall 2-03-quiz1a.cpp -o a

#include <iostream>

void printA()
{
    std::cout << "A\n";
}

void printB()
{
    std::cout << "B\n";
}

int main()
{
    printA();
    printB();

    return 0;
}
