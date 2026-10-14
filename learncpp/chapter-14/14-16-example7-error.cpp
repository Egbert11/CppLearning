// ============================================================
// 来源小节：14.16 Converting constructors and the explicit keyword
// 示例说明：把构造函数标记为 explicit 后，它不再作为转换构造函数，print(5)
//           因无法隐式转换而编译失败。
// 原文链接：https://www.learncpp.com/cpp-tutorial/converting-constructors-and-the-explicit-keyword/
// 备注：本节代码为按原文描述忠实重建。
//
// *** 本文件为预期编译失败示例（-error），请勿"修复" ***
// 预期错误：print(5); 处——Dollars(int) 是 explicit，不能用做隐式转换
//           （cannot convert 'int' to 'Dollars'）。
// ============================================================
#include <iostream>

class Dollars
{
private:
    int m_dollars{};

public:
    // --- 原文示例片段（原 Example 8）---
    explicit Dollars(int d) // now explicit
        : m_dollars{ d }
    {
    }
    // --- 原文示例片段结束 ---

    int getDollars() const { return m_dollars; }
};

void print(Dollars d)
{
    std::cout << "$" << d.getDollars();
}

int main()
{
    print(5); // compilation error because Dollars(int) is explicit

    return 0;
}
