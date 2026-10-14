// ============================================================
// 来源小节：17.6 std::array and enumerations
// 示例说明：用 static_assert 把数组长度与枚举项个数绑定，忘记给新枚举项
//           准备初值时编译立即失败；同样可用于校验两个数组长度一致。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdarray-and-enumerations/
// 预期错误：编译错误——static assertion failed: std::size(testScores) == max_students。
// 备注：本文件为预期编译失败示例（-error），请勿修复。
// ============================================================
#include <array>

namespace Students
{
    enum Names
    {
        kenny,
        kyle,
        stan,
        butters,
        cartman,
        max_students
    };
}

int main()
{
    constexpr std::array testScores { 78, 94, 66, 77 }; // oops, only 4 values

    static_assert(std::size(testScores) == Students::max_students); // compile error: static_assert condition failed

    return 0;
}
