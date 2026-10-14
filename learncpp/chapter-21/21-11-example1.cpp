// 来源小节：21.11 Overloading typecasts
// 示例说明：Cents 提供了从 int 的转换构造函数和 getCents()/setCents() 访问函数。
//           调用方必须显式调用 getCents() 才能把 Cents 当 int 用；编译器不把访问函数
//           视为“类型转换”，代码里也到处是访问函数调用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-typecasts/
// 说明：本节代码为按原文描述重建。
// 预期输出：7

#include <iostream>

class Cents
{
private:
    int m_cents{};

public:
    Cents(int cents = 0)
        : m_cents{ cents }
    {
    }

    int getCents() const { return m_cents; }
    void setCents(int cents) { m_cents = cents; }
};

void printInt(int value)
{
    std::cout << value;
}

int main()
{
    // --- 原文示例片段 ---
    Cents cents{ 7 };
    printInt(cents.getCents()); // print 7
    // --- 原文示例片段结束 ---

    std::cout << '\n';

    return 0;
}
