// 来源小节：8.10 For statements
// 示例说明：递减循环，从 9 数到 0
// 原文链接：https://www.learncpp.com/cpp-tutorial/for-statements/
// 预期输出：9 8 7 6 5 4 3 2 1 0

#include <iostream>

int main()
{
    for (int i{ 9 }; i >= 0; --i)
        std::cout << i << ' ';

    std::cout << '\n';

    return 0;
}
