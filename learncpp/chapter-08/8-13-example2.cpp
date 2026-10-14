// 来源小节：8.13 Introduction to random number generation
// 示例说明：一个简单的 16 位线性同余生成器（LCG）伪随机数生成器
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-random-number-generation/
// For illustrative purposes only, don't use this（仅供演示，不要使用）
// 说明：本节代码为按原文描述重建。该 PRNG 质量很差，输出会出现奇偶交替。

#include <iostream>

unsigned int LCG16() // our PRNG
{
    static unsigned int s_state{ 0 }; // our PRNG state

    // Generate the next number

    // Due to our "magic numbers", the following is equivalent to:
    // s_state = (s_state * 8253729) + 2396403;
    s_state = 8253729 * s_state + 2396403; // first we modify the state
    return s_state % 32768; // then we use the new state to generate the next number in the sequence
}

int main()
{
    // Print the first 100 numbers
    for (int count{ 1 }; count <= 100; ++count)
    {
        std::cout << LCG16() << '\t';

        // If we've printed 10 numbers, start a new row
        if (count % 10 == 0)
            std::cout << '\n';
    }

    return 0;
}
