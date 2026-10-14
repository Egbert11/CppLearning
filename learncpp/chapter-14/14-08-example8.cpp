// ============================================================
// 来源小节：14.8 The benefits of data hiding (encapsulation)
// 示例说明：把内部实现改为数组，接口保持不变——使用方（main）完全无需修改。
//           这体现了数据隐藏的核心好处：实现可变，接口不变。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-benefits-of-data-hiding-encapsulation/
// 备注：本节代码为按原文描述忠实重建。原文未给出输出。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 8）---
class Something
{
private:
    int m_value[3]; // reimplemented as an array, but the interface is unchanged

public:
    void setValue1(int value) { m_value[0] = value; }
    int getValue1() const { return m_value[0]; }
};

int main()
{
    Something something;
    something.setValue1(5); // no changes needed here
    std::cout << something.getValue1() << '\n';

    return 0;
}

// 预期输出：
// 5
