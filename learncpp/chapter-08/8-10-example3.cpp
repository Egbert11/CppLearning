// 来源小节：8.10 For statements
// 示例说明：用 for 循环实现 pow(base, exponent)，返回 std::int64_t
// 原文链接：https://www.learncpp.com/cpp-tutorial/for-statements/

#include <cstdint>
#include <iostream>

// returns the value base ^ exponent -- watch out for overflow!
std::int64_t pow(int base, int exponent)
{
    std::int64_t total{ 1 };

    for (int count{ 0 }; count < exponent; ++count)
        total *= base;

    return total;
}

int main()
{
    std::cout << pow(2, 0) << '\n'; // 1
    std::cout << pow(2, 1) << '\n'; // 2
    std::cout << pow(2, 2) << '\n'; // 4
    std::cout << pow(2, 3) << '\n'; // 8
    std::cout << pow(3, 2) << '\n'; // 9
    std::cout << pow(3, 3) << '\n'; // 27
    std::cout << pow(4, 3) << '\n'; // 64
    std::cout << pow(5, 2) << '\n'; // 25
    std::cout << pow(2, 8) << '\n'; // 256
    std::cout << pow(2, 16) << '\n'; // 65536
    std::cout << pow(2, 32) << '\n'; // 4294967296
    // 2^64 = 18446744073709551616 超出 int64 范围，产生有符号溢出（UB）；
    // 实际打印值依实现而定（本机为 0），这正是 "watch out for overflow!" 所指。
    std::cout << pow(2, 64) << '\n'; // overflow! result is implementation-defined / UB

    return 0;
}
