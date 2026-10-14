// 来源小节：8.10 For statements
// 示例说明：把示例 1 的 for 循环改写为等价的 while 循环（外层块让 i 具有循环作用域）
// 原文链接：https://www.learncpp.com/cpp-tutorial/for-statements/
// 预期输出：1 2 3 4 5 6 7 8 9 10

#include <iostream>

int main()
{
    { // outer braces give i loop scope
        int i{ 1 }; // init-statement (only once, at loop start)
        while (i <= 10) // condition
        {
            std::cout << i << ' '; // loop body
            ++i; // end-expression
        }
    } // i goes out of scope here

    std::cout << '\n';

    return 0;
}
