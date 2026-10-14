// 来源小节：8.6 Switch fallthrough and scoping
// 示例说明：本节 quiz 解答——用 switch 实现一个简单计算器 calculate(x, y, op)。
// 原文链接：https://www.learncpp.com/cpp-tutorial/switch-fallthrough-and-scoping/
//
// 编译：g++ -std=c++20 -Wall 8-06-example9-quiz.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 原文示例运行：
//   Enter an integer: 6
//   Enter another integer: 2
//   Enter a mathematical operator (+, -, *, /, or %): *
//   6 * 2 is 12

#include <iostream>

int calculate(int x, int y, char op)
{
    switch (op)
    {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        return x / y;
    case '%':
        return x % y;
    default:
        std::cout << "calculate(): Unhandled case\n";
        return 0;
    }
}

int main()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;

    std::cout << "Enter another integer: ";
    int y{};
    std::cin >> y;

    std::cout << "Enter a mathematical operator (+, -, *, /, or %): ";
    char op{};
    std::cin >> op;

    // We'll call calculate first so an invalid operator prints an error message on its own line
    int result{ calculate(x, y, op) };
    std::cout << x << ' ' << op << ' ' << y << " is " << result << '\n';

    return 0;
}
