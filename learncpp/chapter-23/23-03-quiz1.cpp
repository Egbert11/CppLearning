// ============================================================
// 来源小节：23.3 Aggregation（测验解答）
// 示例说明：用 std::vector<std::reference_wrapper<const Teacher>>
//           实现 Department：可添加多名教师、以"引用"方式持有它们，
//           打印时用 teacher.get().getName()。教师比部门活得更久。
// 原文链接：https://www.learncpp.com/cpp-tutorial/aggregation/
// 预期输出：
//   Department: Bob Frank Beth
//   Bob still exists!
//   Frank still exists!
//   Beth still exists!
// 备注：本节代码为按原文描述重建（原 Example 2 的调用 + Example 5 的解答）。
// ============================================================
#include <functional> // std::reference_wrapper
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

class Teacher
{
private:
    std::string m_name{};

public:
    Teacher(std::string_view name)
        : m_name{ name }
    {
    }

    std::string_view getName() const { return m_name; }
};

class Department
{
private:
    std::vector<std::reference_wrapper<const Teacher>> m_teachers{};

public:
    Department() = default;

    void add(const Teacher& teacher)
    {
        m_teachers.emplace_back(teacher);
    }

    friend std::ostream& operator<<(std::ostream& out, const Department& department)
    {
        out << "Department: ";

        for (const auto& teacher : department.m_teachers)
            out << teacher.get().getName() << ' ';

        return out;
    }
};

int main()
{
    // Create a teacher outside the scope of the Department
    Teacher t1{ "Bob" };
    Teacher t2{ "Frank" };
    Teacher t3{ "Beth" };

    {
        // Create a department and add some Teachers to it
        Department department{}; // create an empty Department

        department.add(t1);
        department.add(t2);
        department.add(t3);

        std::cout << department << '\n';

    } // department goes out of scope here and is destroyed

    std::cout << t1.getName() << " still exists!\n";
    std::cout << t2.getName() << " still exists!\n";
    std::cout << t3.getName() << " still exists!\n";

    return 0;
}
