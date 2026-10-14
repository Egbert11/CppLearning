// 来源小节：21.11 Overloading typecasts
// 示例说明：类型转换可重载成“转换成任意类型（含自定义类）”。Dollars 定义 operator Cents()
//           把美元转成分；Dollars{9} 先隐式转成 Cents，再隐式转成 int，得到 900。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-typecasts/
// 说明：本节代码为按原文描述重建。原文提示：此处其实用“转换构造函数”更合适。
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
    operator int() const { return m_cents; }

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
    std::cout << cents; // cents will be implicitly cast to an int here
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
