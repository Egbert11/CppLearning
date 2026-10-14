// 来源小节：8.x Chapter 8 summary and quiz（测验 2 额外加分）
// 示例说明：优化版 isPrime()——跳过偶数除数，只检查到 x 的平方根
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-8-summary-and-quiz/
// 预期输出：Success!
// 提示：对 a >= 0、b >= 0，a <= sqrt(b) 等价于 a * a <= b，故可用 test * test <= x 代替 std::sqrt。

// 强制启用 assert
#undef NDEBUG

#include <cassert> // for assert
#include <cmath>   // (原文额外包含，用于说明 std::sqrt 的位置)
#include <iostream>

bool isPrime(int x)
{
    if (x <= 1)
        return false;

    if (x == 2)
        return true;

    if (x % 2 == 0)
        return false;

    // 只检查到 x 的平方根：用 test * test <= x 避免在循环条件里调用 std::sqrt
    // 且每次递增 2，跳过所有偶数
    for (int test{ 3 }; test * test <= x; test += 2)
    {
        if (x % test == 0)
            return false;
    }

    return true;
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
