// ============================================================
// 来源小节：16.9 Array indexing and length using enumerators
// 示例说明：重载一元 operator+，把 enum class 枚举量转换为其底层类型，
//           于是 +StudentNames::stan 这种写法简洁地替代了满屏的 static_cast。
// 原文链接：https://www.learncpp.com/cpp-tutorial/array-indexing-and-length-using-enumerators/
// 预期输出：The class has 5 students
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <type_traits> // for std::underlying_type_t
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

// Overload the unary + operator to convert StudentNames to the underlying type
constexpr auto operator+(StudentNames a) noexcept
{
    return static_cast<std::underlying_type_t<StudentNames>>(a);
}

int main()
{
    std::vector<int> testScores(+StudentNames::max_students);

    testScores[+StudentNames::stan] = 76;

    std::cout << "The class has " << +StudentNames::max_students << " students\n";

    return 0;
}
