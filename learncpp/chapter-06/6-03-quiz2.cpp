// ============================================================
// 来源小节：6.3 Remainder and Exponentiation
// 示例说明：测验第 2 题解答——读取整数，用 isEven() 判断并输出奇偶。
// 原文链接：https://www.learncpp.com/cpp-tutorial/remainder-and-exponentiation/
// 备注：本节代码为按原文描述忠实重建。
//   示例运行：输入 5 输出 "5 is odd"。
// ============================================================
#include <iostream>

// --- 原文示例片段 ---
constexpr bool isEven(int x)
{
    return (x % 2) == 0;
}

int main()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;

    if (isEven(x))
        std::cout << x << " is even\n";
    else
        std::cout << x << " is odd\n";

    return 0;
}
// --- 原文示例片段结束 ---
