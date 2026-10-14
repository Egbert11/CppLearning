// ============================================================
// 来源小节：17.1 Introduction to std::array
// 示例说明：std::array 的长度模板实参必须是常量表达式，可用整型字面量、
//           constexpr 变量、无作用域枚举项或宏来表示（宏虽可用但不推荐）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdarray/
// 预期输出：（无输出，仅演示合法的长度写法）
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <array>

int main()
{
    [[maybe_unused]] std::array<int, 7> a {}; // Using a literal constant

    constexpr int len { 8 };
    [[maybe_unused]] std::array<int, len> b {}; // Using a constexpr variable

    enum Colors
    {
        red,
        green,
        blue,
        max_colors
    };
    [[maybe_unused]] std::array<int, max_colors> c {}; // Using an enumerator

#define DAYS_PER_WEEK 7
    [[maybe_unused]] std::array<int, DAYS_PER_WEEK> d {}; // Using a macro (avoid)
#undef DAYS_PER_WEEK

    return 0;
}
