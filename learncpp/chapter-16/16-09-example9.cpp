// ============================================================
// 来源小节：16.9 Array indexing and length using enumerators
// 示例说明：enum class 下用 static_cast 逐个转换枚举量——可行但啰嗦、代码杂乱。
// 原文链接：https://www.learncpp.com/cpp-tutorial/array-indexing-and-length-using-enumerators/
// 预期输出：The class has 5 students
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

enum class StudentNames
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
    std::vector<int> testScores(static_cast<int>(StudentNames::max_students));

    testScores[static_cast<int>(StudentNames::stan)] = 76;

    std::cout << "The class has " << static_cast<int>(StudentNames::max_students) << " students\n";

    return 0;
}
