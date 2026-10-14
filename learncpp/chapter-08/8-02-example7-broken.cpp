// 来源小节：8.2 If statements and blocks
// 示例说明：坏实践演示——单语句分支的两种"意外改变逻辑"的危险用法（原文示例 7 与示例 8）。
//           (1) 想把 gamble() 也变条件语句时只加了缩进；
//           (2) 用注释掉 purchaseBeer() 调试时，checkout() 意外变成条件语句。
// 原文链接：https://www.learncpp.com/cpp-tutorial/if-statements-and-blocks/
//
// 编译：g++ -std=c++20 -Wall 8-02-example7-broken.cpp -o a
//
// 本节代码为按原文描述重建。原文示例 7、8 都是片段（函数未定义），这里补上桩函数使程序可编译。

#include <iostream>

void purchaseBeer()          { std::cout << "purchaseBeer()\n"; }
void gamble()                { std::cout << "gamble()\n"; }
void addBeerToCart()         { std::cout << "addBeerToCart()\n"; }
void checkout()              { std::cout << "checkout()\n"; }

int main()
{
    constexpr int minDrinkingAge{ 21 };
    constexpr int age{ 30 };

    // --- 原文示例片段：不小心改变了逻辑 ---
    if (age >= minDrinkingAge)
        purchaseBeer();
        gamble(); // 这一行总是执行（即便 age < minDrinkingAge）
    // --- 原文示例片段结束 ---

    // --- 原文示例片段：调试时的陷阱 ---
    if (age >= minDrinkingAge)
        addBeerToCart();

    checkout(); // 这一行总是执行

    // 如果为了调试把上面那行注释掉：
    // if (age >= minDrinkingAge)
    //     addBeerToCart();

    // checkout(); // 现在它变成了条件语句！
    // --- 原文示例片段结束 ---

    return 0;
}
