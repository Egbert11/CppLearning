// ============================================================
// 来源小节：17.2 std::array length and indexing
// 示例说明：std::get<>() 的下标必须是 constexpr；越界下标会触发库内
//           static_assert，产生编译错误。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdarray-length-and-indexing/
// 预期错误：编译错误——static assertion failed: array index is within bounds。
// 备注：本文件为预期编译失败示例（-error），请勿修复。
// ============================================================
#include <array>
#include <iostream>

int main()
{
    constexpr std::array prime{ 2, 3, 5, 7, 11 };

    std::cout << std::get<3>(prime) << '\n'; // print the value of element with index 3 (7)
    std::cout << std::get<9>(prime) << '\n'; // invalid index (compile error)

    return 0;
}
