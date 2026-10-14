// ============================================================
// 来源小节：24.2 Basic inheritance in C++（原 Example 1）
// 示例说明：一个通用的 Person 类，持有姓名与年龄，并提供访问器。
//           成员暂设为 public，仅为让示例保持简单（正常应为 private）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/basic-inheritance-in-c/
// 预期输出：
//   Joe is 42 years old.
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

int main()
{
    Person joe{ "Joe", 42 };

    std::cout << joe.getName() << " is " << joe.getAge() << " years old.\n";

    return 0;
}
