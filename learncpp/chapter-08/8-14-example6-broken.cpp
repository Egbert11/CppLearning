// 来源小节：8.14 Generating random numbers using Mersenne Twister
// 示例说明：常见错误——在每次调用的函数内部创建并播种一个新引擎。
//           这既低效，又很可能产生很差的随机性（每次调用都重新播种）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/generating-random-numbers-using-mersenne-twister/
// 说明：本节代码为按原文描述重建。

#include <iostream>
#include <random> // for std::mt19937 and std::uniform_int_distribution

int getCard()
{
    std::mt19937 mt{ std::random_device{}() }; // this gets created and seeded every time the function is called
    std::uniform_int_distribution card{ 1, 52 };
    return card(mt);
}

int main()
{
    std::cout << getCard() << '\n';

    return 0;
}
