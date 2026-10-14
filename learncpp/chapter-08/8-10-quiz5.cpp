// 来源小节：8.10 For statements（本节 Quiz 第 5 题解答）
// 示例说明：扩展版 FizzBuzz——为 7 的倍数加上 "pop"。
//           用一个 bool printed 标志，只使用 4 个 if 语句。
// 原文链接：https://www.learncpp.com/cpp-tutorial/for-statements/

#include <iostream>

void fizzbuzz(int count)
{
    for (int i{ 1 }; i <= count; ++i)
    {
        bool printed{ false };

        if (i % 3 == 0)
        {
            std::cout << "fizz";
            printed = true;
        }

        if (i % 5 == 0)
        {
            std::cout << "buzz";
            printed = true;
        }

        if (i % 7 == 0)
        {
            std::cout << "pop";
            printed = true;
        }

        if (!printed)
            std::cout << i;

        std::cout << '\n';
    }
}

int main()
{
    fizzbuzz(150);

    return 0;
}
