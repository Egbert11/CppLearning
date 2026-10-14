// 来源小节：7.9 Inline functions and variables
// 示例说明：普通（非内联）min() 函数，被 main 调用两次，用于说明函数调用开销。
// 原文链接：https://www.learncpp.com/cpp-tutorial/inline-functions-and-variables/
//
// 本节示例为按原文描述重建（对应原文 Example 1；Example 2 展示的是"若编译器把调用展开成
// ((5 < 6) ? 5 : 6) 与 ((3 < 2) ? 3 : 2)"的概念，无法以源码形式呈现）。
// 预期输出：
// 5
// 2

#include <iostream>

int min(int x, int y)
{
    return (x < y) ? x : y;
}

int main()
{
    std::cout << min(5, 6) << '\n';
    std::cout << min(3, 2) << '\n';

    return 0;
}
