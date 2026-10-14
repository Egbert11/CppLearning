// 来源小节：8.11 Break and continue
// 示例说明：在每个 switch case 末尾使用 break，防止 fallthrough 到下一个 case
// 原文链接：https://www.learncpp.com/cpp-tutorial/break-and-continue/
// 预期输出：2 + 3 = 5

#include <iostream>

void printMath(int x, int y, char ch)
{
    switch (ch)
    {
    case '+':
        std::cout << x << " + " << y << " = " << x + y << '\n';
        break; // don't fall-through to next case
    case '-':
        std::cout << x << " - " << y << " = " << x - y << '\n';
        break; // don't fall-through to next case
    case '*':
        std::cout << x << " * " << y << " = " << x * y << '\n';
        break; // don't fall-through to next case
    case '/':
        std::cout << x << " / " << y << " = " << x / y << '\n';
        break;
    }
}

int main()
{
    printMath(2, 3, '+');

    return 0;
}
