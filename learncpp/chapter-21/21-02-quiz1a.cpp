// 来源小节：21.2 Overloading the arithmetic operators using friend functions
// 示例说明：测验 1a 解答——Fraction 类，含分子/分母成员和 print() 成员函数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-arithmetic-operators-using-friend-functions/
// 说明：本节代码取自原文（逐字保留）。
// 预期输出：
//   1/4
//   1/2

#include <iostream>

class Fraction
{
private:
	int m_numerator { 0 };
	int m_denominator { 1 };

public:
	explicit Fraction(int numerator, int denominator=1)
		: m_numerator{numerator}, m_denominator{denominator}
	{
	}

	void print() const
	{
		std::cout << m_numerator << '/' << m_denominator << '\n';
	}
};

int main()
{
	Fraction f1 {1, 4};
	f1.print();

	Fraction f2 {1, 2};
	f2.print();

	return 0;
}
