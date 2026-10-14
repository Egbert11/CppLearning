// ============================================================
// 来源小节：14.16 Converting constructors and the explicit keyword
// 示例说明：转换构造函数带来的"意外"隐式转换——Dollars(int) 默认是转换构造
//           函数，print(5) 会静默地把 5 转成 Dollars 并打印 $5。
// 原文链接：https://www.learncpp.com/cpp-tutorial/converting-constructors-and-the-explicit-keyword/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 7）---
class Dollars
{
private:
    int m_dollars{};

public:
    Dollars(int d)
        : m_dollars{ d }
    {
    }

    int getDollars() const { return m_dollars; }
};

void print(Dollars d)
{
    std::cout << "$" << d.getDollars();
}

int main()
{
    print(5); // implicitly converts int 5 to a Dollars

    return 0;
}
// --- 原文示例片段结束 ---

// 预期输出：
// $5
