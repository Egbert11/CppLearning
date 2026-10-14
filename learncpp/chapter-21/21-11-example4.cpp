// 来源小节：21.11 Overloading typecasts
// 示例说明：把 Cents 的 operator int() 标为 explicit 后，它不再参与隐式转换，
//           只能通过 static_cast（或直接的圆括号/花括号初始化）调用；
//           而 Dollars::operator Cents() 未标 explicit，Dollars→Cents 仍是隐式转换。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-typecasts/
// 说明：本节代码为按原文描述重建。
// 预期输出：900

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

    // Overloaded int cast
    explicit operator int() const { return m_cents; }

    int getCents() const { return m_cents; }
};

class Dollars
{
private:
    int m_dollars{};

public:
    Dollars(int dollars = 0)
        : m_dollars{ dollars }
    {
    }

    // Allow us to convert Dollars into Cents
    operator Cents() const { return Cents{ m_dollars * 100 }; }
};

void printCents(Cents cents)
{
    std::cout << static_cast<int>(cents); // now we must explicitly cast
}

int main()
{
    // --- 原文示例片段 ---
    Dollars dollars{ 9 };
    printCents(dollars); // dollars will be implicitly cast to a Cents here
    // --- 原文示例片段结束 ---

    std::cout << '\n';

    return 0;
}
