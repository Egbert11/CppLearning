// ============================================================
// 来源小节：17.3 Passing and returning std::array
// 示例说明：把 operator[] 换成 std::get<3>()，越界访问就从未定义行为变成
//           编译期错误（库内 static_assert 检查下标是否小于长度）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/passing-and-returning-stdarray/
// 预期错误：编译错误——static assertion failed: array index is within bounds。
// 备注：本文件为预期编译失败示例（-error），请勿修复。
// ============================================================
#include <array>
#include <cstddef>
#include <iostream>

template <typename T, std::size_t N>
void printElement3(const std::array<T, N>& arr)
{
    std::cout << std::get<3>(arr) << '\n'; // compile error if N <= 3
}

int main()
{
    std::array arr{ 9, 7 }; // only 2 elements
    printElement3(arr);     // compile error: array index is within bounds

    return 0;
}
