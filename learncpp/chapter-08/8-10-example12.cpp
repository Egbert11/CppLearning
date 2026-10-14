// 来源小节：8.10 For statements
// 示例说明：嵌套 for 循环——外层字母 a..e，内层对每个字母打印 0 1 2
// 原文链接：https://www.learncpp.com/cpp-tutorial/for-statements/
// 预期输出：a012 / b012 / c012 / d012 / e012（各占一行）

#include <iostream>

int main()
{
    for (char c{ 'a' }; c <= 'e'; ++c) // outer loop on letters
    {
        std::cout << c; // print our letter first

        for (int i{ 0 }; i < 3; ++i) // inner loop on all numbers
            std::cout << i;

        std::cout << '\n';
    }

    return 0;
}
