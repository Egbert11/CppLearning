// ============================================================
// 来源小节：16.9 Array indexing and length using enumerators
// 示例说明：用非 constexpr 的 Students::Names 变量作下标——当该枚举的底层类型
//           默认是有符号时，可能触发"符号转换"警告。
// 原文链接：https://www.learncpp.com/cpp-tutorial/array-indexing-and-length-using-enumerators/
// 预期输出：（无输出）
// 备注：本节代码为按原文描述重建。
//   GCC/Clang 对"所有枚举量都非负"的无作用域枚举通常选择 unsigned int 作底层类型，
//   因此用 -Wall 编译这里可能并不会真的告警（原文用 may，即可能）。
//   若想观察到符号转换警告，可用 -Wsign-conversion，或按 Example 4 显式指定底层类型。
// ============================================================
#include <vector>

namespace Students
{
    enum Names
    {
        kenny,   // 0
        kyle,    // 1
        stan,    // 2
        butters, // 3
        cartman, // 4
        max_students // 5
    };
}

int main()
{
    std::vector testScores { 78, 94, 66, 77, 14 };
    Students::Names name { Students::stan }; // non-constexpr

    // may trigger a sign conversion warning if Students::Names defaults to a signed underlying type
    testScores[name] = 76;

    return 0;
}
