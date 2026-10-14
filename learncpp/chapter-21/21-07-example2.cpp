// 来源小节：21.7 Overloading the comparison operators
// 示例说明：为 Cents 独立定义全部六个比较运算符——每个都直接比较 m_cents。
//           可以看到大部分实现只是重复模板，比较逻辑越复杂重复越明显。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-comparison-operators/
// 说明：本节代码取自原文（逐字保留）。
// 预期输出：
//   a dime is greater than a nickel.
//   a dime is greater than or equal to a nickel.
//   a dime is not equal to a nickel.

#include <iostream>

class Cents
{
private:
    int m_cents;

public:
    Cents(int cents)
	: m_cents{ cents }
	{}

    friend bool operator== (const Cents& c1, const Cents& c2);
    friend bool operator!= (const Cents& c1, const Cents& c2);

    friend bool operator< (const Cents& c1, const Cents& c2);
    friend bool operator> (const Cents& c1, const Cents& c2);

    friend bool operator<= (const Cents& c1, const Cents& c2);
    friend bool operator>= (const Cents& c1, const Cents& c2);
};

bool operator== (const Cents& c1, const Cents& c2)
{
    return c1.m_cents == c2.m_cents;
}

bool operator!= (const Cents& c1, const Cents& c2)
{
    return c1.m_cents != c2.m_cents;
}

bool operator> (const Cents& c1, const Cents& c2)
{
    return c1.m_cents > c2.m_cents;
}

bool operator< (const Cents& c1, const Cents& c2)
{
    return c1.m_cents < c2.m_cents;
}

bool operator<= (const Cents& c1, const Cents& c2)
{
    return c1.m_cents <= c2.m_cents;
}

bool operator>= (const Cents& c1, const Cents& c2)
{
    return c1.m_cents >= c2.m_cents;
}

int main()
{
    Cents dime{ 10 };
    Cents nickel{ 5 };

    if (nickel > dime)
        std::cout << "a nickel is greater than a dime.\n";
    if (nickel >= dime)
        std::cout << "a nickel is greater than or equal to a dime.\n";
    if (nickel < dime)
        std::cout << "a dime is greater than a nickel.\n";
    if (nickel <= dime)
        std::cout << "a dime is greater than or equal to a nickel.\n";
    if (nickel == dime)
        std::cout << "a dime is equal to a nickel.\n";
    if (nickel != dime)
        std::cout << "a dime is not equal to a nickel.\n";

    return 0;
}
