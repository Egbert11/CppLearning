// ============================================================
// 来源小节：16.9 Array indexing and length using enumerators
// 示例说明：显式把枚举底层类型声明为 unsigned int，从而让非 constexpr 的枚举变量
//           不再触发符号转换（因为 name 本身就是无符号的）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/array-indexing-and-length-using-enumerators/
// 预期输出：（无输出）
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <vector>

namespace Students
{
    enum Names : unsigned int // explicitly specifies the underlying type is unsigned int
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

    testScores[name] = 76; // not a sign conversion since name is unsigned

    return 0;
}
