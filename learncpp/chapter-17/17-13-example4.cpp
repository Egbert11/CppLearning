// ============================================================
// 来源小节：17.13 Multidimensional std::array
// 示例说明：把别名模板推广到三维（原 Example 5）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/multidimensional-stdarray/
// 预期输出：42
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <array>
#include <iostream>

// An alias template for a three-dimensional std::array
template <typename T, std::size_t Row, std::size_t Col, std::size_t Depth>
using Array3d = std::array<std::array<std::array<T, Depth>, Col>, Row>;

int main()
{
    Array3d<int, 2, 3, 4> arr{}; // a 2x3x4 array of int
    arr[1][2][3] = 42;

    std::cout << arr[1][2][3] << '\n'; // 42

    return 0;
}
