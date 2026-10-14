// 来源小节：8.10 For statements
// 示例说明：条件用 operator< 的循环。即使循环体跳过了哨兵值 10，循环仍会终止。
// 原文链接：https://www.learncpp.com/cpp-tutorial/for-statements/
// 预期输出：0 1 2 3 4 5 6 7 8 9

#include <iostream>

int main()
{
    for (int i { 0 }; i < 10; ++i) // condition uses operator<
    {
        std::cout << i << ' ';

        // if i is 9, then we set it to 11 to jump over the sentinel value of 10
        if (i == 9)
            ++i; // jump over value 10
    }

    std::cout << '\n';

    return 0;
}
