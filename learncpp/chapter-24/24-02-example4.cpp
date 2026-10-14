// ============================================================
// 来源小节：24.2 Basic inheritance in C++（原 Example 7）
// 示例说明：Supervisor 派生自 Employee（而 Employee 派生自 Person），
//           构成一条继承链。Supervisor 只添加一个"最多管理 5 名雇员"的
//           数组，同时继承 Employee 与 Person 的成员。
// 原文链接：https://www.learncpp.com/cpp-tutorial/basic-inheritance-in-c/
// 预期输出：
//   Supervisor Sam (id 999) earns at rate 35.5
// 备注：本节代码为按原文描述重建（原文 Example 7 只给出类定义，未给 main）。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

class Person
{
public:
    std::string m_name{};
    int m_age{};

    Person(std::string_view name = "", int age = 0)
        : m_name{ name }, m_age{ age }
    {
    }

    const std::string& getName() const { return m_name; }
    int getAge() const { return m_age; }
};

class Employee : public Person
{
public:
    double m_hourlySalary{};
    long m_employeeID{};

    Employee(double hourlySalary = 0.0, long employeeID = 0)
        : m_hourlySalary{ hourlySalary }, m_employeeID{ employeeID }
    {
    }

    void printNameAndSalary() const
    {
        std::cout << m_name << ": " << m_hourlySalary << '\n';
    }
};

class Supervisor : public Employee
{
public:
    // This Supervisor can oversee a max of 5 employees
    long m_overseesIDs[5]{};
};

int main()
{
    Supervisor sam{};
    sam.m_name = "Sam";
    sam.m_employeeID = 999;
    sam.m_hourlySalary = 35.5;

    std::cout << "Supervisor " << sam.getName()
              << " (id " << sam.m_employeeID << ')'
              << " earns at rate " << sam.m_hourlySalary << '\n';

    return 0;
}
