// 来源小节：1.5 Introduction to iostream: cout, cin, and endl
// 示例说明：打印数字字面量与变量的值；用多个 << 拼接输出；文本与变量混合输出。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-iostream-cout-cin-and-endl/
//
// 预期输出：
//   4
//   5
//   Hello world!
//   x is equal to: 5

#include <iostream>

int main()
{
    // --- 原文示例片段：打印数字字面量 ---
    std::cout << 4;
    // --- 原文示例片段结束 ---
    std::cout << '\n';

    // --- 原文示例片段：打印变量的值 ---
    int x{ 5 };
    std::cout << x;
    // --- 原文示例片段结束 ---
    std::cout << '\n';

    // --- 原文示例片段：用多个 << 拼接输出 ---
    std::cout << "Hello" << " world!";
    // --- 原文示例片段结束 ---
    std::cout << '\n';

    // --- 原文示例片段：一条语句中同时输出文本与变量 ---
    std::cout << "x is equal to: " << x;
    // --- 原文示例片段结束 ---
    std::cout << '\n';

    return 0;
}
