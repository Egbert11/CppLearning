// ============================================================
// 来源小节：16.2 Introduction to std::vector and list constructors
// 示例说明：用下标运算符 operator[] 访问元素（返回引用），并把前 5 个质数求和。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdvector-and-list-constructors/
// 预期输出：
//   The first prime number is: 2
//   The second prime number is: 3
//   The sum of the first 5 primes is: 28
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    std::vector primes { 2, 3, 5, 7, 11 }; // first 5 prime numbers (as int)

    std::cout << "The first prime number is: " << primes[0] << '\n';
    std::cout << "The second prime number is: " << primes[1] << '\n';
    std::cout << "The sum of the first 5 primes is: "
              << primes[0] + primes[1] + primes[2] + primes[3] + primes[4] << '\n';

    return 0;
}
