// ============================================================
// 来源小节：14.8 The benefits of data hiding (encapsulation)
// 示例说明：封装版 Something——数据成员私有，只通过 setValue1()/getValue1() 访问。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-benefits-of-data-hiding-encapsulation/
// 备注：本节代码为按原文描述忠实重建。原文未给出输出。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 7）---
class Something
{
private:
    int m_value1 {};
    int m_value2 {};
    int m_value3 {};

public:
    void setValue1(int value) { m_value1 = value; }
    int getValue1() const { return m_value1; }
};

int main()
{
    Something something;
    something.setValue1(5);
    std::cout << something.getValue1() << '\n';

    return 0;
}

// 预期输出：
// 5
