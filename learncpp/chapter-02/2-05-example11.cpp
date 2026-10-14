// 来源小节：2.5 Introduction to local scope
// 示例说明：临时对象 —— getValueFromUser() 按值返回，把 input 的副本存到一个临时对象中，
//           该临时对象在创建它的完整表达式结束时被销毁。
//           预期交互（用户输入 4）：
//           Enter an integer: 4
//           4
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-local-scope/
//
// 编译：g++ -std=c++20 -Wall 2-05-example11.cpp -o a

#include <iostream>

int getValueFromUser()
{
    std::cout << "Enter an integer: ";
    int input{};
    std::cin >> input;

    return input; // return a copy of input to the caller
}

int main()
{
    std::cout << getValueFromUser() << '\n'; // where does the returned value get copied to?

    return 0;
}
