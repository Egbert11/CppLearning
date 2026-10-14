// 来源小节：1.8 Whitespace and basic formatting
// 示例说明：演示字符串字面量内部空白被保留、引号内不能换行，
//           以及相邻字符串字面量自动拼接。
// 原文链接：https://www.learncpp.com/cpp-tutorial/whitespace-and-basic-formatting/
//
// 编译：g++ -std=c++20 -Wall 1-08-example2.cpp -o example2

#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::cout << "Hello world!";
    // --- 原文示例片段结束 ---
    std::cout << '\n';

    // --- 原文示例片段 ---
    std::cout << "Hello          world!"; // 引号内的空白原样保留，输出与上一行不同
    // --- 原文示例片段结束 ---
    std::cout << '\n';

    // 原文中不被允许的写法：字符串字面量内部不能直接换行
    // std::cout << "Hello
    //      world!"; // Not allowed!

    // --- 原文示例片段 ---
    std::cout << "Hello "
        "world!"; // prints "Hello world!"（相邻字符串字面量自动拼接）
    // --- 原文示例片段结束 ---
    std::cout << '\n';

    return 0;
}
