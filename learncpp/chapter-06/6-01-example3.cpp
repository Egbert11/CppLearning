// ============================================================
// 来源小节：6.1 Operator precedence and associativity
// 示例说明：把每个 getValue() 调用拆成独立语句后，实参求值顺序确定，结果唯一。
// 原文链接：https://www.learncpp.com/cpp-tutorial/operator-precedence-and-associativity/
// 备注：本节代码为按原文描述忠实重建。
//       输入 1、2、3 时，无论编译器如何，a/b/c 的取值顺序都被语句固定，输出恒为 7。
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
    int a{ getValue() }; // will execute first
    int b{ getValue() }; // will execute second
    int c{ getValue() }; // will execute third

    printCalculation(a, b, c); // this line is not ambiguous
    // --- 原文示例片段结束 ---

    return 0;
}
