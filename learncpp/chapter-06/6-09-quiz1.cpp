// ============================================================
// 来源小节：6.x Chapter 6 summary and quiz（官网编号 6.x，本仓库命名为 6-09）
// 示例说明：测验第 1 题解答——实现 getQuantityPhrase() 与 getApplesPluralized()。
//           getApplesPluralized() 必须使用条件运算符。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-6-summary-and-quiz/
// 备注：本节代码为按原文描述忠实重建。
//   示例运行（输入 1）：
//     Mary has a few apples.
//     How many apples do you have? 1
//     You have a single apple.
// ============================================================
#include <iostream>
#include <string_view>

// --- 原文示例片段（参考解答）---
std::string_view getQuantityPhrase(int num)
{
    if (num < 0)
        return "negative";
    if (num == 0)
        return "no";
    if (num == 1)
        return "a single";
    if (num == 2)
        return "a couple of";
    if (num == 3)
        return "a few";
    return "many";
}

std::string_view getApplesPluralized(int num)
{
    return (num == 1) ? "apple" : "apples"; // must use the conditional operator
}

int main()
{
    constexpr int maryApples { 3 };
    std::cout << "Mary has " << getQuantityPhrase(maryApples) << ' ' << getApplesPluralized(maryApples) << ".\n";

    std::cout << "How many apples do you have? ";
    int numApples{};
    std::cin >> numApples;

    std::cout << "You have " << getQuantityPhrase(numApples) << ' ' << getApplesPluralized(numApples) << ".\n";

    return 0;
}
// --- 原文示例片段结束 ---
