// ============================================================
// 来源小节：24.2 Basic inheritance in C++（原 Example 3 / 4）
// 示例说明：BaseballPlayer 公有继承 Person。main 中直接给继承来的
//           m_name 赋值，再用继承来的 getName() 打印，证明子类可直接
//           使用基类的成员。
// 原文链接：https://www.learncpp.com/cpp-tutorial/basic-inheritance-in-c/
// 预期输出：
//   Joe
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

// BaseballPlayer publicly inherits from Person
class BaseballPlayer : public Person
{
public:
    double m_battingAverage{};
    int m_homeRuns{};

    BaseballPlayer(double battingAverage = 0.0, int homeRuns = 0)
        : m_battingAverage{ battingAverage }, m_homeRuns{ homeRuns }
    {
    }
};

int main()
{
    // Create a new BaseballPlayer object
    BaseballPlayer joe{};
    // Assign it a name (we can do this directly because m_name is public)
    joe.m_name = "Joe";
    // Print out the name
    std::cout << joe.getName() << '\n';

    return 0;
}
