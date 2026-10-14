// ============================================================
// 来源小节：18.2 Introduction to iterators
// 示例说明：用四种方式遍历同一个 std::array（CTAD 推导为 std::array<int, 7>）：
//           ① while + 显式下标；② for + 显式下标；③ for + 指针
//           （ptr != &arr[0] + length，ptr 会被自增故不能是 const）；
//           ④ 范围 for 循环。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-iterators/
// 预期输出：四行，均为 `0 1 2 3 4 5 6`
// 备注：本节代码为按原文描述重建；示例使用 C++17 的类模板实参推导（CTAD）。
// ============================================================
#include <array>
#include <cstddef>
#include <iostream>

int main()
{
    std::array arr{ 0, 1, 2, 3, 4, 5, 6 }; // class template argument deduction (C++17)

    std::size_t length{ std::size(arr) };

    // while-loop with explicit index
    std::size_t index{ 0 };
    while (index < length)
    {
        std::cout << arr[index] << ' ';
        ++index;
    }
    std::cout << '\n';

    // for-loop with explicit index
    for (index = 0; index < length; ++index)
    {
        std::cout << arr[index] << ' ';
    }
    std::cout << '\n';

    // for-loop with pointer (Note: ptr can't be const, because we increment it)
    for (auto ptr{ &arr[0] }; ptr != (&arr[0] + length); ++ptr)
    {
        std::cout << *ptr << ' ';
    }
    std::cout << '\n';

    // range-based for-loop
    for (int i : arr)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}
