// 来源小节：1.8 Whitespace and basic formatting
// 示例说明：演示排版的好坏对比——难以阅读的单行写法 vs. 加入换行、
//           缩进和空行的可读写法（糟糕版本以注释保留作对照）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/whitespace-and-basic-formatting/
//
// 编译：g++ -std=c++20 -Wall 1-08-example3.cpp -o example3

#include <iostream>

// 原文中“难以阅读”的版本（本示例片段，保留作对比，未参与编译）：
// #include <iostream>
// int main(){std::cout<<"Hello world";return 0;}

// --- 原文示例片段（可读版本）---
#include <iostream>

int main()
{
    std::cout << "Hello world";

    return 0;
}
// --- 原文示例片段结束 ---
