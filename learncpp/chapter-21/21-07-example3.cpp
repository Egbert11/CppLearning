// 来源小节：21.7 Overloading the comparison operators
// 示例说明：只真正实现 == 与 <，其余四个由它们推导：
//           != 是 == 的取反；> 是把 < 的两个参数对调；<= 是 !(<)；
//           >= 是 !(>)。这样逻辑只写两处，维护时更省事。
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

    friend bool operator== (const Cents& c1, const Cents& c2) { return c1.m_cents == c2.m_cents; }
    friend bool operator!= (const Cents& c1, const Cents& c2) { return !(operator==(c1, c2)); }

    friend bool operator< (const Cents& c1, const Cents& c2) { return c1.m_cents < c2.m_cents; }
    friend bool operator> (const Cents& c1, const Cents& c2) { return operator<(c2, c1); }

    friend bool operator<= (const Cents& c1, const Cents& c2) { return !(operator>(c1, c2)); }
    friend bool operator>= (const Cents& c1, const Cents& c2) { return !(operator<(c1, c2)); }

};

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
