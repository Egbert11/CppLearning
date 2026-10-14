// 来源小节：20.3 Recursion（Quiz 3b）
// 示例说明：printBinary 的改进版，改用 unsigned int 形参并只递归到 n > 1，
//           因此也能打印 0 和负数（负数会打印其全部 32 位补码位型）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/recursion/
// 说明：本节代码为按原文描述重建。有符号/无符号的转换保持位型不变。
// 交互运行示例：
//   Enter an integer: -15
//   11111111111111111111111111110001
//   Enter an integer: 0
//   0

#include <iostream>

// --- 原文示例片段 ---
void printBinary(unsigned int n)
{
    if (n > 1) // we only recurse if n > 1, so this is our termination case for n == 0
        printBinary(n / 2);

    std::cout << n % 2;
}
// --- 原文示例片段结束 ---

int main()
{
    int x{};
    std::cout << "Enter an integer: ";
    std::cin >> x;

    // static_cast 保持位型不变，所以负数会打印全部 32 位
    printBinary(static_cast<unsigned int>(x));
    std::cout << '\n';

    return 0;
}
