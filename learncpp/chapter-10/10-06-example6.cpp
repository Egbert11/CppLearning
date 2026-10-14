// 来源小节：10.6 Explicit type conversion (casting) and static_cast
// 示例说明：隐式窄化（int -> char）通常会产生警告；用 static_cast<char> 显式表达
//           后不再警告。（对应原文示例 9、10）
// 原文链接：https://www.learncpp.com/cpp-tutorial/explicit-type-conversion-casting-and-static-cast/
//
// 编译：g++ -std=c++20 -Wall 10-06-example6.cpp -o a
//       注：隐式窄化的警告（-Wconversion/-Wsign-conversion）默认不在 -Wall 中；
//           若显式加上 -Wconversion，示例 9 那行会告警，示例 10 那行不会。
//
// 本节代码为按原文描述重建。

#include <iostream>

int main()
{
    int i{ 48 };

    // --- 原文示例片段（示例 9） ---
    char ch = i; // implicit narrowing conversion
    // --- 原文示例片段结束 ---

    // --- 原文示例片段（示例 10） ---
    char ch2{ static_cast<char>(i) }; // explicit narrowing conversion, no warning
    // --- 原文示例片段结束 ---

    std::cout << ch << ' ' << ch2 << '\n'; // 0 0

    return 0;
}
