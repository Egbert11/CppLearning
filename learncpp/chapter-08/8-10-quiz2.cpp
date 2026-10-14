// 来源小节：8.10 For statements（本节 Quiz 第 2 题解答）
// 示例说明：sumTo(value) 返回 1 累加到 value 的和
// 原文链接：https://www.learncpp.com/cpp-tutorial/for-statements/

#include <iostream>

int sumTo(int value)
{
    int total{ 0 };
    for (int i{ 1 }; i <= value; ++i)
        total += i;

    return total;
}

int main()
{
    std::cout << sumTo(5) << '\n';  // 15
    std::cout << sumTo(10) << '\n'; // 55
    std::cout << sumTo(1) << '\n';  // 1
    std::cout << sumTo(0) << '\n';  // 0

    return 0;
}
