// ============================================================
// 来源小节：16.9 Array indexing and length using enumerators
// 示例说明：把枚举改成 enum class 后，枚举量不再隐式转换为整型，于是
//           作 vector 长度、作下标、配合 operator<< 输出都会编译失败。
// 原文链接：https://www.learncpp.com/cpp-tutorial/array-indexing-and-length-using-enumerators/
// 预期错误：本文件预期编译失败（勿修复）。三处错误分别对应：
//   1) no conversion from StudentNames to std::size_t（构造 vector 尺寸）
//   2) no conversion from StudentNames to std::size_t（作下标）
//   3) no matching operator<<（无法输出枚举量）
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

enum class StudentNames // now an enum class
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
    // compile error: no conversion from StudentNames to std::size_t
    std::vector<int> testScores(StudentNames::max_students);

    // compile error: no conversion from StudentNames to std::size_t
    testScores[StudentNames::stan] = 76;

    // compile error: no conversion from StudentNames to any type that operator<< can output
    std::cout << "The class has " << StudentNames::max_students << " students\n";

    return 0;
}
