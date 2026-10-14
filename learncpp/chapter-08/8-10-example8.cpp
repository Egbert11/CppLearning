// 来源小节：8.10 For statements
// 示例说明：off-by-one 错误——本意是打印 1..5，却误用 < 而非 <=，只打印到 4
// 原文链接：https://www.learncpp.com/cpp-tutorial/for-statements/
// 预期输出：1 2 3 4

#include <iostream>

int main()
{
    for (int i{ 1 }; i < 5; ++i) // oops, we used operator< instead of operator<=
        std::cout << i << ' ';

    std::cout << '\n';

    return 0;
}
