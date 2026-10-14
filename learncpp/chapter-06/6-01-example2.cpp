// ============================================================
// 来源小节：6.1 Operator precedence and associativity
// 示例说明：实参求值顺序有歧义的程序。
//           Clang 从左到右求值实参，GCC 从右到左，结果不同。
// 原文链接：https://www.learncpp.com/cpp-tutorial/operator-precedence-and-associativity/
// 备注：本节代码为按原文描述忠实重建。
//       输入 1、2、3 时，若实参从左到右求值 -> 1 + (2 * 3) = 7；
//       若从右到左求值 -> 3 + (2 * 1) = 5。
// ============================================================
#include <iostream>

int getValue()
{
    std::cout << "Enter an integer: ";

    int x{};
    std::cin >> x;
    return x;
}

void printCalculation(int x, int y, int z)
{
    std::cout << x + (y * z);
}

int main()
{
    // --- 原文示例片段 ---
    printCalculation(getValue(), getValue(), getValue()); // this line is ambiguous
    // --- 原文示例片段结束 ---

    return 0;
}
