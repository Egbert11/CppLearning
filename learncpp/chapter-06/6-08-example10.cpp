// ============================================================
// 来源小节：6.8 Logical operators
// 示例说明：原始的 isEven()——判断余数是否为 0。
// 原文链接：https://www.learncpp.com/cpp-tutorial/logical-operators/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段 ---
bool isEven(int x)
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
