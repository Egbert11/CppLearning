// 来源小节：8.10 For statements
// 示例说明：省略 init-statement 与 end-expression，只保留条件的 for 循环
// 原文链接：https://www.learncpp.com/cpp-tutorial/for-statements/
// 预期输出：0 1 2 3 4 5 6 7 8 9

#include <iostream>

int main()
{
    int i{ 0 }; // i 必须在循环外定义并手动初始化
    for ( ; i < 10; ) // no init-statement or end-expression
    {
        std::cout << i << ' ';
        ++i; // 手动递增
    }

    std::cout << '\n';

    return 0;
}
