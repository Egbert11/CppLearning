// ============================================================
// 来源小节：17.7 Introduction to C-style arrays
// 示例说明：Quiz #1 解答——把 `constexpr std::array<int, 3> a{};` 改写成等价
//           的 C 风格数组"分配 3 个 int"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-c-style-arrays/
// 预期输出：3
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <array>
#include <iostream>

int main()
{
    [[maybe_unused]] constexpr std::array<int, 3> a{}; // the std::array form
    constexpr int b[3] {};                            // allocate 3 ints

    std::cout << std::size(b) << '\n';

    return 0;
}
