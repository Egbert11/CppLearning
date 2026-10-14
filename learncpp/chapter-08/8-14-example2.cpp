// 来源小节：8.14 Generating random numbers using Mersenne Twister
// 示例说明：用 std::uniform_int_distribution 把引擎输出转换成 1..6 的骰子点数
// 原文链接：https://www.learncpp.com/cpp-tutorial/generating-random-numbers-using-mersenne-twister/
// 说明：本节代码为按原文描述重建。

#include <iostream>
#include <random> // for std::mt19937 and std::uniform_int_distribution

int main()
{
    std::mt19937 mt{};

    // Create a reusable random number generator that generates uniform numbers between 1 and 6
    std::uniform_int_distribution die6{ 1, 6 }; // for C++14, use std::uniform_int_distribution<> die6{ 1, 6 };

    // Print a bunch of random numbers
    for (int count{ 1 }; count <= 40; ++count)
    {
        std::cout << die6(mt) << '\t'; // generate a roll of the die here

        // If we've printed 10 numbers, start a new row
        if (count % 10 == 0)
            std::cout << '\n';
    }

    return 0;
}
