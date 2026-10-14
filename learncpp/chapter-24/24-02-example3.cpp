// ============================================================
// 来源小节：24.2 Basic inheritance in C++（原 Example 5 / 6）
// 示例说明：Employee 公有继承 Person，添加 m_hourlySalary、m_employeeID
//           以及 printNameAndSalary()，后者同时用到自身与父类的成员。
// 原文链接：https://www.learncpp.com/cpp-tutorial/basic-inheritance-in-c/
// 预期输出：
//   Frank: 20.25
// 备注：本节代码为按原文描述重建。
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

// Employee publicly inherits from Person
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

int main()
{
    Employee frank{ 20.25, 12345 };
    frank.m_name = "Frank"; // we can do this because m_name is public

    frank.printNameAndSalary();

    return 0;
}
