// ============================================================
// 来源小节：14.16 Converting constructors and the explicit keyword
// 示例说明：explicit 构造函数仍支持直接初始化与直接列表初始化；把隐式转换改写
//           成显式构造即可通过编译，并且表达了明确的意图。
// 原文链接：https://www.learncpp.com/cpp-tutorial/converting-constructors-and-the-explicit-keyword/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

class Dollars
{
private:
    int m_dollars{};

public:
    explicit Dollars(int d)
        : m_dollars{ d }
    {
    }

    int getDollars() const { return m_dollars; }
};

void print(Dollars d)
{
    std::cout << "$" << d.getDollars() << '\n';
}

int main()
{
    // --- 原文示例片段（原 Example 9）---
    Dollars d1(5); // ok: direct initialization (explicit constructor allowed)
    Dollars d2{5}; // ok: direct list initialization
    // --- 原文示例片段结束 ---

    (void)d1; (void)d2;

    // --- 原文示例片段（原 Example 10 / 11）---
    print(Dollars{5});                 // ok: explicitly create a Dollars
    print(static_cast<Dollars>(5));    // ok: static_cast will use explicit constructors
    // --- 原文示例片段结束 ---

    return 0;
}

// 预期输出：
// $5
// $5
