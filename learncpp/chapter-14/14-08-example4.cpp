// ============================================================
// 来源小节：14.8 The benefits of data hiding (encapsulation)
// 示例说明：不再存储成对的 firstInitial，而由 firstInitial() 就地计算——
//           彻底消除"两个数据必须同步"的不变式。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-benefits-of-data-hiding-encapsulation/
// 备注：本节代码为按原文描述忠实重建。原文未给出输出，这里补了打印以观察结果。
//       剩余不变式：名字不得为空，否则对空串调用 front() 是未定义行为。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

// --- 原文示例片段（原 Example 4）---
class Employee
{
private:
    std::string m_name { "John" };

public:
    void setName(std::string_view name) { m_name = name; }

    char firstInitial() const { return m_name.front(); }

    void print() const
    {
        std::cout << m_name << " has first initial " << firstInitial() << '\n';
    }
};

int main()
{
    Employee e{}; // defaults to "John"
    e.setName("Mark");
    e.print();

    return 0;
}

// 预期输出：
// Mark has first initial M
