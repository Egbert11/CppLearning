// ============================================================
// 来源小节：5.2 Literals
// 示例说明：顺序编号/计数字面量一般不是魔法数字，给它们起名（如 player1）
//           并不会更清晰。
// 原文链接：https://www.learncpp.com/cpp-tutorial/literals/
// ============================================================
#include <iostream>

void printPlayerInfo(int id)
{
    std::cout << "Player " << id << '\n';
}

int main()
{
    // --- 原文示例片段（示例 15）---
    // okay: these are just sequential ids/counts
    printPlayerInfo(1); // `1` would not really benefit from being named `player1` instead
    printPlayerInfo(2);
    // --- 原文示例片段结束 ---

    return 0;
}
