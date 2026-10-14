// ============================================================
// 来源小节：17.1 Introduction to std::array
// 示例说明：operator[] 不做边界检查，用越界下标访问元素是未定义行为。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdarray/
// 预期输出：7（随后越界访问的结果依实现而定）
// 备注：-ub 未定义行为演示。本仓库所用 MSYS2 GCC 15.2 的 libstdc++ 默认开启
//       _GLIBCXX_ASSERTIONS，越界 operator[] 会触发内部断言并 abort（实测退出码
//       127）；在其他实现上可能打印垃圾值或崩溃，均属未定义行为。
// ============================================================
#include <array>
#include <iostream>

int main()
{
    constexpr std::array<int, 5> prime{ 2, 3, 5, 7, 11 };

    std::cout << prime[3] << '\n'; // print the value of element with index 3 (7)
    std::cout << prime[9] << '\n'; // invalid index (undefined behavior)

    return 0;
}
