// 来源小节：20.1 Function Pointers（Quiz 1）
// 示例说明：用 std::function 实现一个简单的四则运算计算器：
//           根据用户输入的运算符返回对应的函数指针，再调用它。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-pointers/
// 说明：本节代码为按原文描述重建。交互运行示例：
//   Enter an integer: 8
//   Enter an operation ('+', '-', '*', '/'): *
//   Enter an integer: 21
//   8 * 21 = 168

#include <functional>
#include <iostream>

int getInteger()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;
    return x;
}

char getOperation()
{
    char op{};

    do
    {
        std::cout << "Enter an operation ('+', '-', '*', '/'): ";
        std::cin >> op;
    }
    while (op != '+' && op != '-' && op != '*' && op != '/');

    return op;
}

int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int divide(int x, int y)
{
    return x / y;
}

// --- 原文示例片段 ---
using ArithmeticFunction = std::function<int(int, int)>;

ArithmeticFunction getArithmeticFunction(char op)
{
    switch (op)
    {
    case '+': return &add;
    case '-': return &subtract;
    case '*': return &multiply;
    case '/': return &divide;
    }

    return nullptr;
}
// --- 原文示例片段结束 ---

int main()
{
    int x{ getInteger() };
    char op{ getOperation() };
    int y{ getInteger() };

    // --- 原文示例片段 ---
    ArithmeticFunction fcn{ getArithmeticFunction(op) };
    if (fcn)
        std::cout << x << ' ' << op << ' ' << y << " = " << fcn(x, y) << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
