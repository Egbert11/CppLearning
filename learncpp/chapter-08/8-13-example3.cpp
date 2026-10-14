// 来源小节：8.13 Introduction to random number generation
// 示例说明：把 PRNG 状态移到全局变量，用用户输入的种子来播种，并打印前 10 个数
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-random-number-generation/
// 说明：本节代码为按原文描述重建。相同种子产生相同序列（确定性），不同种子产生不同序列。
// 这是交互式程序，需要用户输入种子值。

#include <iostream>

unsigned int g_state{ 0 };

void seedPRNG(unsigned int seed)
{
    g_state = seed;
}

// Generate the next number
unsigned int LCG16()
{
    // Since we are using a global variable, we replace the static local state with g_state
    g_state = 8253729 * g_state + 2396403;
    return g_state % 32768;
}

void print10()
{
    // Print the first 10 numbers
    for (int count{ 1 }; count <= 10; ++count)
        std::cout << LCG16() << '\t';

    std::cout << '\n';
}

int main()
{
    unsigned int x {};
    std::cout << "Enter a seed value: ";
    std::cin >> x;

    seedPRNG(x);
    print10();

    return 0;
}
