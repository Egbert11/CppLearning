// ============================================================
// 来源小节：24.4 Constructors and initialization of derived classes（原 Example 9 / 10）
// 示例说明：把 Person / BaseballPlayer 的成员都改为 private，派生类通过
//           : Person{ name, age } 把值向上传给基类构造函数，并只用访问器
//           读取基类成员，从而在保留封装的同时完成初始化。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constructors-and-initialization-of-derived-classes/
// 预期输出：
//   Pedro Cerrano
//   32
//   0.342
//   42
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <string>

class Person
{
private:
    std::string m_name;
    int m_age;

public:
    Person(const std::string& name = "", int age = 0)
        : m_name{ name }, m_age{ age }
    {
    }

    const std::string& getName() const { return m_name; }
    int getAge() const { return m_age; }
};

class BaseballPlayer : public Person
{
private:
    double m_battingAverage{};
    int m_homeRuns{};

public:
    BaseballPlayer(const std::string& name = "", int age = 0,
        double battingAverage = 0.0, int homeRuns = 0)
        : Person{ name, age }, // call Person(const std::string&, int) to initialize these fields
          m_battingAverage{ battingAverage }, m_homeRuns{ homeRuns }
    {
    }

    double getBattingAverage() const { return m_battingAverage; }
    int getHomeRuns() const { return m_homeRuns; }
};

int main()
{
    BaseballPlayer pedro{ "Pedro Cerrano", 32, 0.342, 42 };

    std::cout << pedro.getName() << '\n';
    std::cout << pedro.getAge() << '\n';
    std::cout << pedro.getBattingAverage() << '\n';
    std::cout << pedro.getHomeRuns() << '\n';

    return 0;
}
