// ============================================================
// 来源小节：16.9 Array indexing and length using enumerators
// 示例说明：用计数枚举量 max_students 作为 vector 的长度，并把它当"学生人数"输出；
//           将来在它前面插入新枚举量时，容器会自动变大而无需修改别处。
// 原文链接：https://www.learncpp.com/cpp-tutorial/array-indexing-and-length-using-enumerators/
// 预期输出：The class has 5 students
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
        // add future enumerators here
        max_students // 5
    };
}

int main()
{
    std::vector<int> testScores(Students::max_students); // Create a vector with 5 elements

    testScores[Students::stan] = 76; // we are now updating the test score belonging to stan

    std::cout << "The class has " << Students::max_students << " students\n";

    return 0;
}
