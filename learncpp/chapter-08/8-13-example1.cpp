// 来源小节：8.13 Introduction to random number generation
// 示例说明：用 static 局部变量的"有状态"生成器 plusOne()，每次调用返回递增 1 的数
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-random-number-generation/
// 预期输出：4 换行 5 换行 6
// 说明：本节代码为按原文描述重建。

#include <iostream>

int plusOne()
{
    static int s_state { 3 }; // only initialized the first time this function is called

    // Generate the next number

    ++s_state;      // first we modify the state
    return s_state; // then we use the new state to generate the next number in the sequence
}

int main()
{
    std::cout << plusOne() << '\n';
    std::cout << plusOne() << '\n';
    std::cout << plusOne() << '\n';

    return 0;
}
