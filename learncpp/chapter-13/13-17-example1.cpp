// ============================================================
// 来源小节：13.y Using a language reference（本仓库文件号 13-17）
// 示例说明：在 if 条件中使用变量定义（init-statement），名字在两个分支都可见。
// 原文链接：https://www.learncpp.com/cpp-tutorial/using-a-language-reference/
// 备注：本节代码为按原文描述忠实重建。需交互输入。
// ============================================================
#include <iostream>

int getUserInput()
{
    int i{};
    std::cin >> i;
    return i;
}

int main()
{
    // --- 原文示例片段（原 Example 1）---
    std::cout << "How many bananas did you eat today? \n";

    if (int iBananasEaten{ getUserInput() }; iBananasEaten <= 2)
    {
        std::cout << "Yummy\n";
    }
    else
    {
        std::cout << iBananasEaten << " is a lot!\n"; // iBananasEaten is visible here too
    }

    return 0;
}

// 预期输出（示例输入 1）：
// How many bananas did you eat today?
// 1
// Yummy
//
// 预期输出（示例输入 5）：
// How many bananas did you eat today?
// 5
// 5 is a lot!
