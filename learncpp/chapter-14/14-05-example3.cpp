// ============================================================
// 来源小节：14.5 Public and private members and access specifiers
// 示例说明：setter 示例，同时演示私有数据成员的 m_ 前缀命名约定——它把
//           数据成员与形参、局部变量区分开，避免命名冲突。
// 原文链接：https://www.learncpp.com/cpp-tutorial/public-and-private-members-and-access-specifiers/
// 备注：本节代码为按原文描述忠实重建。原文只给出该成员函数片段，
//       此处为它补一个最小的类与 main() 以便独立编译。
// ============================================================
#include <string>
#include <string_view>

class Person
{
private:
    std::string m_name{};

public:
    // Some member function that sets private member m_name to the value of the name parameter
    void setName(std::string_view name)
    {
        m_name = name;
    }
};

int main()
{
    Person p;
    p.setName("Joe");

    return 0;
}
