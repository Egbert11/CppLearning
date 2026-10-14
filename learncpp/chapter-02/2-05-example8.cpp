// 来源小节：2.5 Introduction to local scope
// 示例说明：旧式 C 风格（不推荐）—— 所有局部变量都声明在函数顶部，之后才赋值，
//           容易让人看不出它们各自的用途。
//           预期交互（用户输入 5、7）：
//           Enter an integer: 5
//           Enter another integer: 7
//           5 + 7 = 12
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-local-scope/
//
// 编译：g++ -std=c++20 -Wall 2-05-example8.cpp -o a

#include <iostream>

int main()
{
    int x{}, y{}, sum{}; // how are these used?

    std::cout << "Enter an integer: ";
    std::cin >> x;

    std::cout << "Enter another integer: ";
    std::cin >> y;

    sum = x + y;
    std::cout << x << " + " << y << " = " << sum << '\n';

    return 0;
}
