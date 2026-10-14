// ============================================================
// 来源小节：14.5 Public and private members and access specifiers
// 示例说明：访问控制是**按类**而非按对象——kisses() 是 Person 的成员函数，
//           因此它可以直接读取另一个 Person 对象 p 的私有成员 p.m_name。
// 原文链接：https://www.learncpp.com/cpp-tutorial/public-and-private-members-and-access-specifiers/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

class Person
{
private:
    std::string m_name{};

public:
    void kisses(const Person& p) const
    {
        std::cout << m_name << " kisses " << p.m_name << '\n';
    }

    void setName(std::string_view name)
    {
        m_name = name;
    }
};

int main()
{
    Person joe;
    joe.setName("Joe");

    Person kate;
    kate.setName("Kate");

    joe.kisses(kate);

    return 0;
}

// 预期输出：
// Joe kisses Kate
