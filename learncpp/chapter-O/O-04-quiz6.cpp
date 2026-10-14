// ============================================================
// 来源小节：O.4 Converting integers between binary and decimal representation
// 示例说明：测验第 6 题解答——读入 0–255 的整数，不使用位运算符与
//           std::bitset，按方法 3（整除取奇偶）打印成 8 位二进制，
//           四位一组、中间空一格。
// 原文链接：https://www.learncpp.com/cpp-tutorial/converting-integers-between-binary-and-decimal-representation/
// ============================================================
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块）。
#include <iostream>

void printBit(int x, int pow)
{
    std::cout << ((x / pow) % 2);
}

void print8BitBinary(int x)
{
    printBit(x, 128);
    printBit(x, 64);
    printBit(x, 32);
    printBit(x, 16);

    std::cout << ' ';

    printBit(x, 8);
    printBit(x, 4);
    printBit(x, 2);
    printBit(x, 1);
}

int main()
{
    std::cout << "Enter an integer between 0 and 255: ";
    int x{};
    std::cin >> x;

    print8BitBinary(x);

    std::cout << '\n';

    return 0;
}
