// ============================================================
// 来源小节：6.6 The conditional operator
// 示例说明：读取两个数并打印较大者。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-conditional-operator/
// 备注：本节代码为按原文描述忠实重建。
//   输入 5 7 -> The max of 5 and 7 is 7.
//   输入 7 5 -> The max of 7 and 5 is 7.
// ============================================================
#include <iostream>

int getValue()
{
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;
    return x;
}

int main()
{
    // --- 原文示例片段 ---
    int x{ getValue() };
    int y{ getValue() };
    int max{ (x > y) ? x : y };

    std::cout << "The max of " << x << " and " << y << " is " << max << ".\n";
    // --- 原文示例片段结束 ---

    return 0;
}
