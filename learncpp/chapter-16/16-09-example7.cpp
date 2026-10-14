// ============================================================
// 来源小节：16.9 Array indexing and length using enumerators
// 示例说明：容器由初始化列表构造、又用枚举量索引时，用 assert 断言
//           容器大小等于计数枚举量，以发现枚举列表与初始化列表不匹配的问题。
// 原文链接：https://www.learncpp.com/cpp-tutorial/array-indexing-and-length-using-enumerators/
// 预期输出：（无输出；断言成立则静默通过）
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <cassert>
#include <vector>

enum StudentNames
{
    kenny,   // 0
    kyle,    // 1
    stan,    // 2
    butters, // 3
    cartman, // 4
    max_students // 5
};

int main()
{
    std::vector testScores { 78, 94, 66, 77, 14 };

    // Ensure the number of test scores is the same as the number of students
    assert(std::size(testScores) == max_students);

    return 0;
}
