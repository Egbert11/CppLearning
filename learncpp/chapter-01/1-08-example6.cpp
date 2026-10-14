// 来源小节：1.8 Whitespace and basic formatting
// 示例说明：演示赋值对齐与注释对齐（难以阅读与易读两种写法对照）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/whitespace-and-basic-formatting/
//
// 编译：g++ -std=c++20 -Wall 1-08-example6.cpp -o example6

#include <iostream>

int main()
{
    int cost;
    int pricePerItem;
    int value;
    int numberOfItems;

    // --- 原文示例片段（赋值未对齐，较难阅读）---
    cost = 57;
    pricePerItem = 24;
    value = 5;
    numberOfItems = 17;
    // --- 原文示例片段结束 ---

    // --- 原文示例片段（赋值按 = 对齐，更易阅读）---
    cost          = 57;
    pricePerItem  = 24;
    value         = 5;
    numberOfItems = 17;
    // --- 原文示例片段结束 ---

    // --- 原文示例片段（注释对齐，更易阅读）---
    std::cout << "Hello world!\n";                  // cout lives in the iostream library
    std::cout << "It is very nice to meet you!\n";  // these comments are easier to read
    std::cout << "Yeah!\n";                         // especially when all lined up
    // --- 原文示例片段结束 ---

    // 让上面的变量被使用，避免 -Wunused-but-set-variable 警告
    std::cout << cost << ' ' << pricePerItem << ' ' << value << ' ' << numberOfItems << '\n';
    return 0;
}
