// ============================================================
// 来源小节：14.8 The benefits of data hiding (encapsulation)
// 示例说明：Yogurt "最差"版——成员函数 print() 即便类已提供 getFlavor()，
//           仍直接访问私有成员 m_flavor（耦合了接口与实现）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-benefits-of-data-hiding-encapsulation/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

// --- 原文示例片段（原 Example 9）---
class Yogurt
{
private:
    std::string m_flavor { "vanilla" };

public:
    void setFlavor(std::string_view flavor) { m_flavor = flavor; }
    const std::string& getFlavor() const { return m_flavor; }

    // worst: even though a getter exists, this member function accesses the data member directly
    void print() const
    {
        std::cout << "The yogurt has flavor " << m_flavor << '\n';
    }
};

int main()
{
    Yogurt y{};
    y.setFlavor("cherry");
    y.print();

    return 0;
}

// 预期输出：
// The yogurt has flavor cherry
