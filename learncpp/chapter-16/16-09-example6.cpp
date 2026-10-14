// ============================================================
// 来源小节：16.9 Array indexing and length using enumerators
// 示例说明：在计数枚举量之前插入一个新枚举量 wendy 后，max_students 自动由 5 变 6，
//           于是用 max_students 定尺寸的 vector 自动扩容，stan 的插入依然有效。
// 原文链接：https://www.learncpp.com/cpp-tutorial/array-indexing-and-length-using-enumerators/
// 预期输出：The class has 6 students
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
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
        wendy,   // 5 (added)
        // add future enumerators here
        max_students // now 6
    };
}

int main()
{
    std::vector<int> testScores(Students::max_students); // will now allocate 6 elements

    testScores[Students::stan] = 76; // still works

    std::cout << "The class has " << Students::max_students << " students\n";

    return 0;
}
