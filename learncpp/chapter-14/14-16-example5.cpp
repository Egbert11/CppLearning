// ============================================================
// 来源小节：14.16 Converting constructors and the explicit keyword
// 示例说明：修复方式二——显式构造 Employee{ "Joe" }，此时只剩
//           const char* -> std::string_view 这一步用户自定义转换。
// 原文链接：https://www.learncpp.com/cpp-tutorial/converting-constructors-and-the-explicit-keyword/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

class Employee
{
private:
    std::string m_name{};

public:
    Employee(std::string_view name)
        : m_name{ name }
    {
    }

    const std::string& getName() const { return m_name; }
};

void printEmployee(Employee e)
{
    std::cout << e.getName();
}

int main()
{
    // --- 原文示例片段（原 Example 6）---
    printEmployee(Employee{ "Joe" });
    // --- 原文示例片段结束 ---

    return 0;
}

// 预期输出：
// Joe
