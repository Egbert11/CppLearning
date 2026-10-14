// 来源小节：2.5 Introduction to local scope
// 示例说明：误用情形 —— getValueFromUser(int val) 把一个本应是局部变量的东西做成了参数，
//           main 传进去的值根本没被用到，徒增复杂度。
//           预期交互（用户输入 4）：
//           Enter an integer: 4
//           4 doubled is: 8
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-local-scope/
//
// 编译：g++ -std=c++20 -Wall 2-05-example9.cpp -o a

#include <iostream>

int getValueFromUser(int val) // val is a parameter, caller must supply it
{
    std::cout << "Enter an integer: ";
    std::cin >> val; // the value passed in as an argument is never used

    return val;
}

int main()
{
    int x{};

    // getValueFromUser takes a parameter, but the argument we pass in isn't used
    x = getValueFromUser(x);

    std::cout << x << " doubled is: " << x * 2 << '\n';

    return 0;
}
