// ============================================================
// 来源小节：6.3 Remainder and Exponentiation
// 示例说明：错误的奇数判断与改正后的写法。
// 原文链接：https://www.learncpp.com/cpp-tutorial/remainder-and-exponentiation/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（错误版本）---
// 对负奇数会失效：-5 % 2 = -1，不等于 1
bool isOddWrong(int x)
{
    return (x % 2) == 1; // fails when x is -5
}

// --- 原文示例片段（改正版本）---
// 与 0 比较，避免符号问题（也可直接写 return (x % 2)）
bool isOddCorrect(int x)
{
    return (x % 2) != 0; // could also write return (x % 2)
}
// --- 原文示例片段结束 ---

int main()
{
    for (int x : { 3, -5, 4, -4 })
    {
        std::cout << "x = " << x
                  << "  isOddWrong = " << isOddWrong(x)
                  << "  isOddCorrect = " << isOddCorrect(x) << '\n';
    }

    return 0;
}
