// 来源小节：1.7 Keywords and naming identifiers
// 示例说明：当描述性名字会变得笨重时，用注释补充说明变量的含义
//           （这里统计的是包含空白与标点在内的字符数）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/keywords-and-naming-identifiers/
//
// 编译：g++ -std=c++20 -Wall 1-07-example3.cpp -o example3

#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    // a count of the number of chars in a piece of text, including whitespace and punctuation
    int numChars {};
    // --- 原文示例片段结束 ---

    numChars = 42;
    std::cout << numChars << '\n';
    return 0;
}
