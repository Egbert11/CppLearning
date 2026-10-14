// ============================================================
// 来源小节：16.9 Array indexing and length using enumerators
// 示例说明：用无作用域枚举量作下标，让 testScores[Students::stan] 这种写法
//           自带含义（自文档化）。枚举量可隐式转换为 std::size_t。
// 原文链接：https://www.learncpp.com/cpp-tutorial/array-indexing-and-length-using-enumerators/
// 预期输出：（无输出）
// 备注：本节代码为按原文描述重建。
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

    testScores[Students::stan] = 76; // we are now updating the test score belonging to stan

    return 0;
}
