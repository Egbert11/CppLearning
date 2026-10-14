// 来源小节：4.10 Introduction to if statements
// 示例说明：进阶——用 switch 语句写紧凑版 isPrime。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-if-statements/
// 原示例只是一个 isPrime 函数片段，这里补一个 main() 调用它。

#include <iostream>

bool isPrime(int x)
{
    switch (x)
    {
        case 2: // if the user entered 2
        case 3: // or if the user entered 3
        case 5: // or if the user entered 5
        case 7: // or if the user entered 7
            return true; // then the digit is prime
    }

    return false; // otherwise the digit must not be prime
}

int main()
{
    std::cout << "Enter a number 0 through 9: ";
    int x {};
    std::cin >> x;

    std::cout << x << (isPrime(x) ? " is prime\n" : " is not prime\n");
    return 0;
}
