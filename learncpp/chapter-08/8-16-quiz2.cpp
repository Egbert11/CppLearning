// 来源小节：8.x Chapter 8 summary and quiz（测验 2 解答）
// 示例说明：用 for 循环实现 isPrime()，配合基于 assert 的测试骨架
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-8-summary-and-quiz/
// 预期输出：Success!

// 强制启用 assert（即使定义了 NDEBUG，release 构建中也保留断言）
#undef NDEBUG

#include <cassert> // for assert
#include <iostream>

bool isPrime(int x)
{
    if (x <= 1)
        return false;

    for (int test{ 2 }; test < x; ++test)
    {
        if (x % test == 0) // if x is evenly divisible
            return false;  // then x is not prime
    }

    return true; // if x is not evenly divisible by any number, then x is prime
}

int main()
{
    assert(!isPrime(0));
    assert(!isPrime(1));
    assert(isPrime(2));
    assert(isPrime(3));
    assert(!isPrime(4));
    assert(isPrime(5));
    assert(isPrime(7));
    assert(!isPrime(9));
    assert(isPrime(11));
    assert(isPrime(13));
    assert(!isPrime(15));
    assert(!isPrime(16));
    assert(isPrime(17));
    assert(isPrime(19));
    assert(isPrime(97));
    assert(!isPrime(99));
    assert(isPrime(13417));

    std::cout << "Success!\n";

    return 0;
}
