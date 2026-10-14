// 来源小节：1.8 Whitespace and basic formatting
// 示例说明：演示缩进、超长行的两种拆分方式，以及把运算符放在续行开头。
// 原文链接：https://www.learncpp.com/cpp-tutorial/whitespace-and-basic-formatting/
//
// 编译：g++ -std=c++20 -Wall 1-08-example5.cpp -o example5

#include <iostream>

int main()
{
    // --- 原文示例片段（缩进）---
    std::cout << "Hello world!\n";     // tabbed in one tab (4 spaces)
    std::cout << "Nice to meet you.\n"; // tabbed in one tab (4 spaces)
    // --- 原文示例片段结束 ---

    // --- 原文示例片段（超长行的两种拆分）---
    std::cout << "This is a really, really, really, really, really, really, really, "
        "really long line\n"; // one extra indentation for continuation line

    std::cout << "This is another really, really, really, really, really, really, really, "
                 "really long line\n"; // text aligned with the previous line for continuation line

    std::cout << "This one is short\n";
    // --- 原文示例片段结束 ---

    // --- 原文示例片段（运算符放在续行开头）---
    std::cout << 3 + 4
        + 5 + 6
        * 7 * 8;
    // --- 原文示例片段结束 ---
    std::cout << '\n';

    return 0;
}
