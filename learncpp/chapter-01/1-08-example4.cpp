// 来源小节：1.8 Whitespace and basic formatting
// 示例说明：演示把一条语句拆成多行书写。
// 原文链接：https://www.learncpp.com/cpp-tutorial/whitespace-and-basic-formatting/
//
// 编译：g++ -std=c++20 -Wall 1-08-example4.cpp -o example4

#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::cout
        << "Hello world"; // works fine
    // --- 原文示例片段结束 ---

    std::cout << '\n';
    return 0;
}
