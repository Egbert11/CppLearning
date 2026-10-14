// ============================================================
// 来源小节：16.2 Introduction to std::vector and list constructors
// 示例说明：打印元素地址，观察 int 元素相邻存放、地址相差 sizeof(int) 字节，
//           体现数组元素在内存中连续分配（contiguous）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdvector-and-list-constructors/
// 预期输出：首行为 "An int is 4 bytes"，随后三个地址十六进制递增（相邻相差 4）。
//           具体地址值因实现/每次运行而异。
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    std::vector primes { 2, 3, 5, 7, 11 }; // first 5 prime numbers (as int)

    std::cout << "An int is " << sizeof(int) << " bytes\n";
    std::cout << &(primes[0]) << '\n';
    std::cout << &(primes[1]) << '\n';
    std::cout << &(primes[2]) << '\n';

    return 0;
}
