// ============================================================
// 来源小节：22.7 Circular dependency issues with std::shared_ptr, and std::weak_ptr
// 示例说明：把 m_partner 改为 std::weak_ptr<Person>（观察者，不计入引用
//           计数），打断循环引用，两个 Person 都能正常销毁。
// 原文链接：https://www.learncpp.com/cpp-tutorial/circular-dependency-issues-with-stdshared_ptr-and-stdweak_ptr/
// 预期输出：
//   Lucy created
//   Ricky created
//   Lucy is now partnered with Ricky
//   Ricky destroyed
//   Lucy destroyed
// 备注：本节代码为按原文描述重建（原 Example 3）。销毁顺序依实现而定。
// ============================================================
#include <iostream>
#include <memory> // for std::shared_ptr and std::weak_ptr
#include <string>

class Person
{
    std::string m_name;
    std::weak_ptr<Person> m_partner; // note: This is now a std::weak_ptr

public:
    Person(const std::string& name) : m_name(name)
    {
        std::cout << m_name << " created\n";
    }

    ~Person()
    {
        std::cout << m_name << " destroyed\n";
    }

    friend bool partnerUp(std::shared_ptr<Person>& p1, std::shared_ptr<Person>& p2)
    {
        if (!p1 || !p2)
            return false;

        p1->m_partner = p2;
        p2->m_partner = p1;

        std::cout << p1->m_name << " is now partnered with " << p2->m_name << '\n';

        return true;
    }
};

int main()
{
    auto lucy{ std::make_shared<Person>("Lucy") };
    auto ricky{ std::make_shared<Person>("Ricky") };

    partnerUp(lucy, ricky);

    return 0;
}
