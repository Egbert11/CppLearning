// 来源小节：8.14 Generating random numbers using Mersenne Twister
// 示例说明：用 std::seed_seq 搭配 8 个 std::random_device 值正确播种（避免播种不足）
// 原文链接：https://www.learncpp.com/cpp-tutorial/generating-random-numbers-using-mersenne-twister/
// 说明：本节代码为按原文描述重建。

#include <iostream>
#include <random> // for std::mt19937 and std::seed_seq

int main()
{
    std::random_device rd{};

    // Create seed_seq with clock and 7 random numbers from std::random_device
    std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() }; // get 8 integers of random numbers from std::random_device for our seed

    std::mt19937 mt{ ss }; // initialize our Mersenne Twister with the std::seed_seq

    std::uniform_int_distribution die6{ 1, 6 };

    for (int count{ 1 }; count <= 40; ++count)
    {
        std::cout << die6(mt) << '\t';

        if (count % 10 == 0)
            std::cout << '\n';
    }

    return 0;
}
