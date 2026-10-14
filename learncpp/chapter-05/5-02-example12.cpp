// ============================================================
// 来源小节：5.2 Literals
// 示例说明：非数值的魔法值——应用名文本。若用字面量，将来改名或复用
//           都要逐处查找替换，改用符号常量更安全。
// 原文链接：https://www.learncpp.com/cpp-tutorial/literals/
// ============================================================
#include <iostream>

void printAppWelcome(const char* appName)
{
    std::cout << "Welcome to " << appName << '\n';
}

int main()
{
    // --- 原文示例片段（示例 12）---
    // bad: app name may be used in other places or change in the future
    printAppWelcome("MyCalculator");
    // --- 原文示例片段结束 ---

    return 0;
}
