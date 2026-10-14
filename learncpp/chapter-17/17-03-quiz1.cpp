// ============================================================
// 来源小节：17.3 Passing and returning std::array
// 示例说明：Quiz 解答——编写函数模板 printArray()，打印任意元素类型、任意
//           长度的 std::array，格式为 "(元素, 元素, ...) has length N"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/passing-and-returning-stdarray/
// 预期输出：The array (1, 4, 9, 16) has length 4
//            The array (h, e, l, l, o) has length 5
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <array>
#include <cstddef>
#include <iostream>

template <typename T, std::size_t N>
void printArray(const std::array<T, N>& arr)
{
    std::cout << "The array (";

    bool first{ true };
    for (const auto& e : arr)
    {
        if (!first)
            std::cout << ", ";
        first = false;
        std::cout << e;
    }

    std::cout << ") has length " << N << '\n';
}

int main()
{
    constexpr std::array arr1 { 1, 4, 9, 16 };
    printArray(arr1);

    constexpr std::array arr2 { 'h', 'e', 'l', 'l', 'o' };
    printArray(arr2);

    return 0;
}
