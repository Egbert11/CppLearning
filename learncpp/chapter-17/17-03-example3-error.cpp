// ============================================================
// 来源小节：17.3 Passing and returning std::array
// 示例说明：只把长度作为模板参数、元素类型固定为 int 是允许的，但用别的
//           元素类型调用就找不到匹配的函数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/passing-and-returning-stdarray/
// 预期错误：编译错误——no matching function for call to 'passByRef(std::array<double, 3>)'。
// 备注：本文件为预期编译失败示例（-error），请勿修复。
// ============================================================
#include <array>
#include <cstddef>
#include <iostream>

template <std::size_t N> // only the length is templated; element type is fixed to int
void passByRef(const std::array<int, N>& arr)
{
    std::cout << arr[0] << '\n';
}

int main()
{
    std::array arr{ 9, 7, 5, 3, 1 };
    passByRef(arr); // OK: int array

    std::array arr2{ 1.2, 3.4, 5.6 }; // double array
    passByRef(arr2); // error: no matching function

    return 0;
}
