// 来源小节：8.10 For statements（本节 Quiz 第 4 题解答）
// 示例说明：fizzbuzz(count) 用 for + if/else-if 链实现 FizzBuzz
// 原文链接：https://www.learncpp.com/cpp-tutorial/for-statements/

#include <iostream>

void fizzbuzz(int count)
{
    for (int i{ 1 }; i <= count; ++i)
    {
        if (i % 3 == 0 && i % 5 == 0)
            std::cout << "fizzbuzz";
        else if (i % 3 == 0)
            std::cout << "fizz";
        else if (i % 5 == 0)
            std::cout << "buzz";
        else
            std::cout << i;

        std::cout << '\n';
    }
}

int main()
{
    fizzbuzz(15);

    return 0;
}
