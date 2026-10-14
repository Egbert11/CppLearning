// ============================================================
// 来源小节：17.6 std::array and enumerations
// 示例说明：CTAD 从初始化列表推导长度，很容易与枚举项的个数不一致——这里
//           只给了 4 个成绩，但枚举有 5 项，用 cartman 作下标就越界。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdarray-and-enumerations/
// 预期输出：不确定（越界读取，输出依实现而定）
// 备注：-ub 未定义行为演示；防止此类错误见 17-06-example2-error.cpp 的
//       static_assert 校验。本仓库 MSYS2 GCC 15.2 的 libstdc++ 默认开启
//       _GLIBCXX_ASSERTIONS，越界 operator[] 会触发断言并 abort（实测退出码 127）。
// ============================================================
#include <array>
#include <iostream>

namespace Students
{
    enum Names
    {
        kenny,       // 0
        kyle,        // 1
        stan,        // 2
        butters,     // 3
        cartman,     // 4
        max_students // 5
    };
}

int main()
{
    constexpr std::array testScores { 78, 94, 66, 77 }; // oops, only 4 values

    std::cout << "Cartman got a " << testScores[Students::cartman] << '\n'; // undefined behavior

    return 0;
}
