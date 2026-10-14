// ============================================================
// 来源小节：14.8 The benefits of data hiding (encapsulation)
// 示例说明：改为 class + 私有成员，只经由 setName() 修改；首字母随名字同步更新，
//           从而维持了不变式。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-benefits-of-data-hiding-encapsulation/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

// --- 原文示例片段（原 Example 3）---
class Employee
{
private:
    std::string m_name {};
    char m_firstInitial {};

public:
    void setName(std::string_view name)
    {
        m_name = name;
        m_firstInitial = name.front(); // keeps the two pieces of data in sync
    }

    void print() const
    {
        std::cout << m_name << " has first initial " << m_firstInitial << '\n';
    }
};

int main()
{
    Employee e{};
    e.setName("John");
    e.print();

    e.setName("Mark");
    e.print();

    return 0;
}

// 预期输出：
// John has first initial J
// Mark has first initial M
