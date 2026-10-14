// 来源小节：21.2 Overloading the arithmetic operators using friend functions
// 示例说明：友元函数直接定义在类内部——它不是成员函数，但定义在类内也是允许的，
//           适合实现很简单的运算符。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-arithmetic-operators-using-friend-functions/
// 说明：本节代码取自原文（逐字保留）。
// 预期输出：I have 14 cents.

#include <iostream>

class Cents
{
private:
	int m_cents {};

public:
	explicit Cents(int cents) : m_cents{ cents } { }

	// add Cents + Cents using a friend function
        // This function is not considered a member of the class, even though the definition is inside the class
	friend Cents operator+(const Cents& c1, const Cents& c2)
	{
		// use the Cents constructor and operator+(int, int)
		// we can access m_cents directly because this is a friend function
		return Cents { c1.m_cents + c2.m_cents };
	}

	int getCents() const { return m_cents; }
};

int main()
{
	Cents cents1{ 6 };
	Cents cents2{ 8 };
	Cents centsSum{ cents1 + cents2 };
	std::cout << "I have " << centsSum.getCents() << " cents.\n";

	return 0;
}
