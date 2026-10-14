// 来源小节：8.14 Generating random numbers using Mersenne Twister
// 示例说明：展示 std::random_device{}() 的"具名变量/具名函数"等价写法
// 原文链接：https://www.learncpp.com/cpp-tutorial/generating-random-numbers-using-mersenne-twister/
// 说明：本节代码为按原文描述重建。
// 下面的 getRandomDeviceValue() 与直接写 std::random_device{}() 等价。

#include <iostream>
#include <random> // for std::random_device

unsigned int getRandomDeviceValue()
{
    std::random_device rd{}; // Create a random device (implemented-defined PRNG)
    return rd();             // Return a random value from it
}

int main()
{
    // 等价写法一：具名函数
    std::cout << getRandomDeviceValue() << '\n';

    // 等价写法二：直接用临时对象的简洁语法
    std::cout << std::random_device{}() << '\n';

    return 0;
}
