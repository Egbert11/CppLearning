// ============================================================
// 来源小节：14.11 Default constructors and default arguments
// 示例说明：Employee 只有需要名字和 id 的构造函数；“全默认”的对象在语义上无效，
//           故未提供默认构造函数，Employee e2{} 无匹配构造函数——预期编译失败。
//           请勿修复此文件。
// 原文链接：https://www.learncpp.com/cpp-tutorial/default-constructors-and-default-arguments/
// 预期错误：g++ 报错类似
//   "error: no matching function for call to 'Employee::Employee(<brace-enclosed initializer list>)'"
// 备注：本节代码为按原文描述忠实重建。此文件故意编译失败。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

// --- 原文示例片段（原 Example 11）---
class Employee
{
private:
    std::string m_name {};
    int m_id {};

public:
    Employee(std::string_view name, int id)
        : m_name { name }, m_id { id }
    {
    }

    void print() const
    {
        std::cout << m_name << ' ' << m_id << '\n';
    }
};

int main()
{
    Employee e1{ "Joe", 1 };
    e1.print();

    Employee e2{}; // compile error: no matching constructor (no default constructor provided)

    return 0;
}
