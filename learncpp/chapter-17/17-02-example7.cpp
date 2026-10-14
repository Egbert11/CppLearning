// ============================================================
// 来源小节：17.2 std::array length and indexing
// 示例说明：三种下标访问方式对比——operator[] 不做边界检查；at() 做运行时
//           边界检查；std::get<>() 把下标作为非类型模板实参，做编译期边界
//           检查（内部用 static_assert）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdarray-length-and-indexing/
// 预期输出：7
//            7
//            7
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <array>
#include <iostream>

int main()
{
    constexpr std::array prime{ 2, 3, 5, 7, 11 };

    std::cout << prime[3] << '\n';           // operator[] : no bounds checking
    std::cout << prime.at(3) << '\n';        // at() : runtime bounds checking
    std::cout << std::get<3>(prime) << '\n'; // std::get : compile-time bounds checking

    return 0;
}
