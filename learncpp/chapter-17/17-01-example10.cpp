// ============================================================
// 来源小节：17.1 Introduction to std::array
// 示例说明：CTAD（类模板实参推导，C++17）可让编译器从初始化列表同时推导出
//           std::array 的元素类型与长度，无需手写模板实参。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdarray/
// 预期输出：1 7.31
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <array>
#include <iostream>

int main()
{
    constexpr std::array a1 { 9, 7, 5, 3, 1 }; // deduced to std::array<int, 5>
    constexpr std::array a2 { 9.7, 7.31 };     // deduced to std::array<double, 2>

    static_assert(a1.size() == 5);
    static_assert(a2.size() == 2);

    std::cout << a1[4] << ' ' << a2[1] << '\n';

    return 0;
}
