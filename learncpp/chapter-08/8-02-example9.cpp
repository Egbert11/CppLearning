// 来源小节：8.2 If statements and blocks
// 示例说明：单行折中风格——把 if/else 分支的语句写在同一行，节省纵向空间。
// 原文链接：https://www.learncpp.com/cpp-tutorial/if-statements-and-blocks/
//
// 编译：g++ -std=c++20 -Wall 8-02-example9.cpp -o a
//
// 本节代码为按原文描述重建（原文示例片段，此处补桩函数与 main）。

#include <iostream>

void purchaseBeer() { std::cout << "Beer purchased.\n"; }

int main()
{
    constexpr int minDrinkingAge{ 21 };
    constexpr int age{ 30 };

    // --- 原文示例片段 ---
    if (age >= minDrinkingAge) purchaseBeer();
    else std::cout << "No drinky for you\n";
    // --- 原文示例片段结束 ---

    return 0;
}
