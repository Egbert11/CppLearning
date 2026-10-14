// 来源小节：7.9 Inline functions and variables
// 示例说明：在 min() 定义上加上 inline 关键字。注意：现代语义下 inline 表示"允许多个定义"，
//           而不是"请求把调用展开"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/inline-functions-and-variables/
//
// 本节示例为按原文描述重建（对应原文 Example 3）。
// 预期输出：
// 5
// 2

#include <iostream>

inline int min(int x, int y) // inline 关键字表示这是一个内联函数
{
    return (x < y) ? x : y;
}

int main()
{
    std::cout << min(5, 6) << '\n';
    std::cout << min(3, 2) << '\n';

    return 0;
}
