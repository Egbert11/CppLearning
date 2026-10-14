// 来源小节：21.5 Overloading operators using member functions
// 示例说明：用友元函数重载 Cents + int 作为对照——左操作数 Cents 是第一个参数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-operators-using-member-functions/
// 说明：本节代码取自原文（逐字保留）。
// 预期输出：I have 8 cents.

#include <iostream>

class Cents
{
private:
    int m_cents {};

public:
    Cents(int cents)
        : m_cents { cents } { }

    // Overload Cents + int
    friend Cents operator+(const Cents& cents, int value);

    int getCents() const { return m_cents; }
};

// note: this function is not a member function!
Cents operator+(const Cents& cents, int value)
{
    return Cents(cents.m_cents + value);
}

int main()
{
	const Cents cents1 { 6 };
	const Cents cents2 { cents1 + 2 };
	std::cout << "I have " << cents2.getCents() << " cents.\n";

	return 0;
}
