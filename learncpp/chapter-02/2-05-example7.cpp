// 来源小节：2.5 Introduction to local scope
// 示例说明：推荐做法 —— 每个局部变量都在使用前就近定义并初始化。
//           预期交互（用户输入 5、7）：
//           Enter an integer: 5
//           Enter another integer: 7
//           5 + 7 = 12
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-local-scope/
//
// 编译：g++ -std=c++20 -Wall 2-05-example7.cpp -o a

#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x; // we can define x right before we use it

    std::cout << "Enter another integer: ";
    int y{};
    std::cin >> y; // we can define y right before we use it

    int sum{ x + y }; // sum is defined right before it's used
    std::cout << x << " + " << y << " = " << sum << '\n';

    return 0;
}
