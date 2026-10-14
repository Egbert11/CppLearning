// 来源小节：21.9 Overloading the subscript operator（测验 1 解答）
// 示例说明：GradeMap 把学生姓名映射到成绩（char）。重载 operator[](std::string_view)：
//           用 std::find_if 查找姓名；找到就返回对应成绩的引用，找不到就新建一条记录。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-subscript-operator/
// 说明：本节代码为按原文描述重建（采用 C++20 的 emplace_back 写法；C++17 及更早的写法见注释）。
// 预期输出：
//   Joe got a grade of A
//   Frank got a grade of B

#include <algorithm> // for std::find_if
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

struct StudentGrade
{
    std::string name{};
    char grade{};
};

class GradeMap
{
private:
    std::vector<StudentGrade> m_map{};

public:
    char& operator[](std::string_view name)
    {
        auto found{ std::find_if(m_map.begin(), m_map.end(),
                                 [name](const StudentGrade& student) { return student.name == name; }) };

        if (found != m_map.end())
        {
            return found->grade;
        }

        // otherwise create a new grade (C++20 and newer)
        m_map.emplace_back(std::string{ name }, 'A');
        return m_map.back().grade;

        // C++17 and older:
        // m_map.push_back({ std::string{ name } });
        // return m_map.back().grade;
    }
};

int main()
{
    GradeMap grades{};

    grades["Joe"] = 'A';
    grades["Frank"] = 'B';

    std::cout << "Joe got a grade of " << grades["Joe"] << '\n';
    std::cout << "Frank got a grade of " << grades["Frank"] << '\n';

    return 0;
}
