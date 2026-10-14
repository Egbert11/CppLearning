// ============================================================
// 来源小节：14.7 Member functions returning references to data members
// 示例说明：用 auto 让编译器从数据成员推导 getter 返回类型，保证不发生转换。
//           缺点：返回类型对读者不可见，所以一般仍偏好显式写出类型。
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
    const auto& getName() const { return m_name; } // uses `auto` to deduce return type from m_name
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
