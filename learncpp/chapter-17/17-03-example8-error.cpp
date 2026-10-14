// ============================================================
// 来源小节：17.3 Passing and returning std::array
// 示例说明：用 static_assert(N > 3) 在编译期为函数模板建立"数组长度必须
//           至少为 4"的前置条件，长度过小则实例化失败。
// 原文链接：https://www.learncpp.com/cpp-tutorial/passing-and-returning-stdarray/
// 预期错误：编译错误——static assertion failed: N > 3。
// 备注：本文件为预期编译失败示例（-error），请勿修复。注意应写
//       static_assert(N > 3) 而不是 static_assert(std::size(arr) > 3)——
//       后者在 C++23 之前因 17.2 的语言缺陷无法编译。
// ============================================================
#include <array>
#include <cstddef>
#include <iostream>

template <typename T, std::size_t N>
void printElement3(const std::array<T, N>& arr)
{
    static_assert(N > 3); // make sure array has at least 4 elements
    std::cout << arr[3] << '\n';
}

int main()
{
    std::array arr{ 9, 7 }; // only 2 elements
    printElement3(arr);     // compile error: static_assert fails

    return 0;
}
