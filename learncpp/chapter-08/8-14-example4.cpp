// 来源小节：8.14 Generating random numbers using Mersenne Twister
// 示例说明：用 std::random_device 的输出来播种，每次运行结果通常不同
// 原文链接：https://www.learncpp.com/cpp-tutorial/generating-random-numbers-using-mersenne-twister/
// 说明：本节代码为按原文描述重建。

#include <iostream>
#include <random> // for std::mt19937 and std::random_device

int main()
{
    std::mt19937 mt{ std::random_device{}() }; // generates a random number with a random seed

    std::uniform_int_distribution die6{ 1, 6 };

    for (int count{ 1 }; count <= 40; ++count)
    {
        std::cout << die6(mt) << '\t';

        if (count % 10 == 0)
            std::cout << '\n';
    }

    return 0;
}
