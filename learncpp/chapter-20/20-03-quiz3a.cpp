// 来源小节：20.3 Recursion（Quiz 3a）
// 示例说明：递归地把一个正整数以二进制打印出来。x == 0 时终止，
//           否则先递归 printBinary(x / 2)，再打印 x % 2（先递归、后打印，
//           所以输出顺序是正确的高位在前）。此版本不处理 0 和负数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/recursion/
// 说明：本节代码为按原文描述重建。交互运行示例：
//   Enter a positive integer: 148
//   10010100

#include <iostream>

// --- 原文示例片段 ---
void printBinary(int x)
{
    // Termination case
    if (x == 0)
        return;

    // Recurse to the next bit
    printBinary(x / 2);

    // Print the remainder
    std::cout << x % 2;
}
// --- 原文示例片段结束 ---

int main()
{
    int x{};
    std::cout << "Enter a positive integer: ";
    std::cin >> x;
    printBinary(x);
    std::cout << '\n';

    return 0;
}
