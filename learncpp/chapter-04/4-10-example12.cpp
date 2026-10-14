// 来源小节：4.10 Introduction to if statements
// 示例说明：进阶——用逻辑或运算符写紧凑版 isPrime。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-if-statements/
// 原示例只是一个 isPrime 函数片段，这里补一个 main() 调用它。

#include <iostream>

bool isPrime(int x)
{
    return x == 2 || x == 3 || x == 5 || x == 7; // if user entered 2 or 3 or 5 or 7 the digit is prime
}

int main()
{
    std::cout << "Enter a number 0 through 9: ";
    int x {};
    std::cin >> x;

    std::cout << x << (isPrime(x) ? " is prime\n" : " is not prime\n");
    return 0;
}
