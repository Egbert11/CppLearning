// ============================================================
// 来源小节：17.3 Passing and returning std::array
// 示例说明：模板函数用 operator[] 固定读取下标 3；对 5 元素数组是安全的。
// 原文链接：https://www.learncpp.com/cpp-tutorial/passing-and-returning-stdarray/
// 预期输出：3
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <array>
#include <cstddef>
#include <iostream>

template <typename T, std::size_t N>
void printElement3(const std::array<T, N>& arr)
{
    std::cout << arr[3] << '\n'; // indexed access
}

int main()
{
    std::array arr{ 9, 7, 5, 3, 1 };
    printElement3(arr); // OK: length 5, index 3 is valid

    return 0;
}
