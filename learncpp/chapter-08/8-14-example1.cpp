// 来源小节：8.14 Generating random numbers using Mersenne Twister
// 示例说明：基本的 mt19937 生成（未播种）。每次运行输出完全相同的序列。
// 原文链接：https://www.learncpp.com/cpp-tutorial/generating-random-numbers-using-mersenne-twister/
// 说明：本节代码为按原文描述重建。

#include <iostream>
#include <random> // for std::mt19937

int main()
{
    std::mt19937 mt{}; // Instantiate a 32-bit Mersenne Twister

    // Print a bunch of random numbers
    for (int count{ 1 }; count <= 40; ++count)
    {
        std::cout << mt() << '\t'; // generate a random number

        // If we've printed 5 numbers, start a new row
        if (count % 5 == 0)
            std::cout << '\n';
    }

    return 0;
}
