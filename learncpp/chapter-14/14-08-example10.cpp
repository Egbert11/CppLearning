// ============================================================
// 来源小节：14.8 The benefits of data hiding (encapsulation)
// 示例说明：Yogurt "较好"版——print() 改为经由 getFlavor() 取数据，不再直接碰成员；
//           但仍作为类成员，接口偏大。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-benefits-of-data-hiding-encapsulation/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

// --- 原文示例片段（原 Example 10）---
class Yogurt
{
private:
    std::string m_flavor { "vanilla" };

public:
    void setFlavor(std::string_view flavor) { m_flavor = flavor; }
    const std::string& getFlavor() const { return m_flavor; }

    // better: uses the getter instead of accessing the data member directly
    void print(std::string_view prefix) const
    {
        std::cout << prefix << ' ' << getFlavor() << '\n';
    }
};

int main()
{
    Yogurt y{};
    y.setFlavor("cherry");
    y.print("The yogurt has flavor");

    return 0;
}

// 预期输出：
// The yogurt has flavor cherry
