// ============================================================
// 来源小节：24.9 Multiple inheritance（原 Example 1）
// 示例说明：Teacher 公有继承 Person 与 Employee（逗号分隔多个基类），把"人"与
//           "雇员"两套属性组合到一起，并在构造函数里分别初始化两个基类。
// 原文链接：https://www.learncpp.com/cpp-tutorial/multiple-inheritance/
// 预期输出：
//   Mary (age 45) works for Boo at wage 14.3, teaches grade 8
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

class Person
{
private:
    std::string m_name{};
    int m_age{};

public:
    Person(std::string_view name, int age)
        : m_name{ name }, m_age{ age }
    {
    }

    const std::string& getName() const { return m_name; }
    int getAge() const { return m_age; }
};

class Employee
{
private:
    std::string m_employer{};
    double m_wage{};

public:
    Employee(std::string_view employer, double wage)
        : m_employer{ employer }, m_wage{ wage }
    {
    }

    const std::string& getEmployer() const { return m_employer; }
    double getWage() const { return m_wage; }
};

// Teacher publicly inherits Person and Employee
class Teacher : public Person, public Employee
{
private:
    int m_teachesGrade{};

public:
    Teacher(std::string_view name, int age, std::string_view employer, double wage, int teachesGrade)
        : Person{ name, age }, Employee{ employer, wage }, m_teachesGrade{ teachesGrade }
    {
    }

    int getGrade() const { return m_teachesGrade; }
};

int main()
{
    Teacher t{ "Mary", 45, "Boo", 14.3, 8 };

    std::cout << t.getName() << " (age " << t.getAge() << ") works for "
              << t.getEmployer() << " at wage " << t.getWage()
              << ", teaches grade " << t.getGrade() << '\n';

    return 0;
}
