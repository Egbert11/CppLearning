// 来源小节：11.2 Function overload differentiation
// 示例说明：无法按返回类型重载时的正确做法——用不同的函数名。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-overload-differentiation/
//
// 编译：g++ -std=c++20 -Wall 11-02-example8.cpp -o a
//
// 本节代码为按原文描述重建（原文只给出声明，这里补上定义与调用以便编译运行）。

#include <cstdlib> // for std::rand, std::srand
#include <ctime>
#include <iostream>

int getRandomInt()
{
    return std::rand() % 100;
}

double getRandomDouble()
{
    return static_cast<double>(std::rand()) / RAND_MAX;
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << "Random int: " << getRandomInt() << '\n';
    std::cout << "Random double: " << getRandomDouble() << '\n';

    return 0;
}
