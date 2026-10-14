// ============================================================
// 来源小节：14.7 Member functions returning references to data members
// 示例说明：getter 按 const 左值引用返回数据成员——推荐做法，无拷贝且安全。
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
    const std::string& getName() const { return m_name; } //  getter returns by const reference
};

int main()
{
    Employee joe{}; // joe exists until end of function
    joe.setName("Joe");

    std::cout << joe.getName(); // returns joe.m_name by reference

    return 0;
}

// 预期输出：
// Joe
