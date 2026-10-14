// ============================================================
// 来源小节：17.7 Introduction to C-style arrays
// 示例说明：C++17 之前没有标准库取长度函数；C++11/14 可用一个按引用接收
//           C 风格数组、返回非类型模板参数 N 的 constexpr 函数模板。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-c-style-arrays/
// 预期输出：The array has: 8 elements
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <cstddef>
#include <iostream>

template <typename T, std::size_t N>
constexpr std::size_t length(const T (&)[N]) noexcept
{
    return N;
}

int main()
{
    int array[8] {};

    std::cout << "The array has: " << length(array) << " elements\n";

    return 0;
}
