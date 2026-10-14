// ============================================================
// 来源小节：17.7 Introduction to C-style arrays
// 示例说明：C++17 的 std::size() 返回无符号 std::size_t 长度；C++20 的
//           std::ssize() 返回有符号长度（通常 std::ptrdiff_t）。二者都不做
//           隐式退化，出错时报编译错误而非悄悄给错结果。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-c-style-arrays/
// 预期输出：5
//            5
// 备注：本节代码为按原文描述重建；<iterator> 是这两个函数的规范头文件。
// ============================================================
#include <iostream>
#include <iterator>

int main()
{
    const int prime[] { 2, 3, 5, 7, 11 };

    std::cout << std::size(prime) << '\n';  // unsigned std::size_t
    std::cout << std::ssize(prime) << '\n'; // signed (probably std::ptrdiff_t)

    return 0;
}
