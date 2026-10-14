// 来源小节：8.10 For statements
// 示例说明：基本 for 循环，自变量从 1 到 10，打印每个值并跟一个空格
// 原文链接：https://www.learncpp.com/cpp-tutorial/for-statements/
// 预期输出：1 2 3 4 5 6 7 8 9 10

#include <iostream>

int main()
{
    for (int i{ 1 }; i <= 10; ++i)
        std::cout << i << ' ';

    std::cout << '\n';

    return 0;
}
