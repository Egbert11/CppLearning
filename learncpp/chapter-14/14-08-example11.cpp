// ============================================================
// 来源小节：14.8 The benefits of data hiding (encapsulation)
// 示例说明：Yogurt "最佳"版——打印写成非成员自由函数，只经公有 getter 访问数据。
//           类只保留必要的 setFlavor()/getFlavor()，接口最小。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-benefits-of-data-hiding-encapsulation/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

// --- 原文示例片段（原 Example 11）---
class Yogurt
{
private:
    std::string m_flavor { "vanilla" };

public:
    void setFlavor(std::string_view flavor) { m_flavor = flavor; }
    const std::string& getFlavor() const { return m_flavor; }
};

// best: print() is a non-member function, not part of the class interface
void print(const Yogurt& y)
{
    std::cout << "The yogurt has flavor " << y.getFlavor() << '\n';
}

int main()
{
    Yogurt y{};
    y.setFlavor("cherry");
    print(y);

    return 0;
}

// 预期输出：
// The yogurt has flavor cherry
