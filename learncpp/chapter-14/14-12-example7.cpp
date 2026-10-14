// ============================================================
// 来源小节：14.12 Delegating constructors
// 示例说明：不委托，而用默认实参 `int id = 0` 把两种调用形态合并为一个构造函数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/delegating-constructors/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

// --- 原文示例片段（原 Example 7）---
class Employee
{
private:
    std::string m_name {};
    int m_id { 0 };

public:
    Employee(std::string_view name, int id = 0)
        : m_name { name }, m_id { id }
    {
        std::cout << "Employee " << m_name << " created\n";
    }
};

int main()
{
    Employee e1{ "James" };
    Employee e2{ "Dave", 42 };

    return 0;
}

// 预期输出：
// Employee James created
// Employee Dave created
