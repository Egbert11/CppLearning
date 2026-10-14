// ============================================================
// 来源小节：6.3 Remainder and Exponentiation
// 示例说明：读取两个整数，输出余数，并判断是否整除。
// 原文链接：https://www.learncpp.com/cpp-tutorial/remainder-and-exponentiation/
// 备注：本节代码为按原文描述忠实重建。
//   示例运行：
//     6 3  -> The remainder is: 0   / 6 is evenly divisible by 3
//     6 4  -> The remainder is: 2   / 6 is not evenly divisible by 4
//     2 4  -> The remainder is: 2   / 2 is not evenly divisible by 4
//     -6 4 -> The remainder is: -2
//     6 -4 -> The remainder is: 2
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;

    std::cout << "Enter another integer: ";
    int y{};
    std::cin >> y;

    std::cout << "The remainder is: " << x % y << '\n';

    if ((x % y) == 0)
        std::cout << x << " is evenly divisible by " << y << '\n';
    else
        std::cout << x << " is not evenly divisible by " << y << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
