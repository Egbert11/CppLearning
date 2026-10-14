// ============================================================
// 来源小节：14.12 Delegating constructors
// 示例说明：把重复的打印抽成私有成员函数 printCreated()，两个构造函数体都只调用它。
//           但两者仍各自初始化相同的成员——这只是部分解决。
// 原文链接：https://www.learncpp.com/cpp-tutorial/delegating-constructors/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

// --- 原文示例片段（原 Example 4）---
class Employee
{
private:
    std::string m_name { "???" };
    int m_id { 0 };
    bool m_isManager { false };

    void printCreated() const
    {
        std::cout << "Employee " << m_name << " created\n";
    }

public:
    Employee(std::string_view name, int id)
        : m_name { name }, m_id { id }
    {
        printCreated();
    }

    Employee(std::string_view name, int id, bool isManager)
        : m_name { name }, m_id { id }, m_isManager { isManager }
    {
        printCreated();
    }
};

int main()
{
    Employee e1{ "James", 7 };
    Employee e2{ "Dave", 42, true };

    return 0;
}

// 预期输出：
// Employee James created
// Employee Dave created
