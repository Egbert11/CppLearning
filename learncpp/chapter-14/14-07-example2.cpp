// ============================================================
// 来源小节：14.7 Member functions returning references to data members
// 示例说明：getter 按值返回数据成员——安全但每次调用都会拷贝整个 string。
// 原文链接：https://www.learncpp.com/cpp-tutorial/member-functions-returning-references-to-data-members/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

class Employee
{
    std::string m_name{};

public:
    void setName(std::string_view name) { m_name = name; }
    std::string getName() const { return m_name; } //  getter returns by value
};

int main()
{
    Employee joe{};
    joe.setName("Joe");
    std::cout << joe.getName();

    return 0;
}

// 预期输出：
// Joe
//
// 说明：每次调用 getName() 都会拷贝 m_name（昂贵），而访问函数常被频繁调用，故通常不是最佳选择。
