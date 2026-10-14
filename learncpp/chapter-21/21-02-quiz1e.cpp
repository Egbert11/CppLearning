// 来源小节：21.2 Overloading the arithmetic operators using friend functions
// 示例说明：测验 1e（加分题）解答——在构造函数里调用 reduce()，用 std::gcd 自动约分，
//           保证所有构造出的 Fraction（含中间结果）都已化到最简；gcd 为 0 时跳过以免除零。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-arithmetic-operators-using-friend-functions/
// 说明：本节代码取自原文（逐字保留）。
// 预期输出：
//   2/5
//   3/8
//   3/20
//   4/5
//   3/4
//   1/4
//   0/1

#include <iostream>
#include <numeric> // for std::gcd

// This version of the Fraction class auto-reduces fractions
class Fraction
{
private:
	int m_numerator{ 0 };
	int m_denominator{ 1 };

public:
	explicit Fraction(int numerator, int denominator = 1)
		: m_numerator{ numerator }, m_denominator{ denominator }
	{
		// We put reduce() in the constructor to ensure any fractions we make get reduced!
		// Since all of the overloaded operators create new Fractions, we can guarantee this will get called here
		reduce();
	}

	void reduce()
	{
		int gcd{ std::gcd(m_numerator, m_denominator) };
		if (gcd) // Make sure we don't try to divide by 0
		{
			m_numerator /= gcd;
			m_denominator /= gcd;
		}
	}

	friend Fraction operator*(const Fraction& f1, const Fraction& f2);
	friend Fraction operator*(const Fraction& f1, int value);
	friend Fraction operator*(int value, const Fraction& f1);

	void print() const
	{
		std::cout << m_numerator << '/' << m_denominator << '\n';
	}
};

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
	return Fraction { f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator };
}

Fraction operator*(const Fraction& f1, int value)
{
	return Fraction { f1.m_numerator * value, f1.m_denominator };
}

Fraction operator*(int value, const Fraction& f1)
{
	return Fraction { f1 * value };
}

int main()
{
	Fraction f1{ 2, 5 };
	f1.print();

	Fraction f2{ 3, 8 };
	f2.print();

	Fraction f3{ f1 * f2 };
	f3.print();

	Fraction f4{ f1 * 2 };
	f4.print();

	Fraction f5{ 2 * f2 };
	f5.print();

	Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
	f6.print();

	Fraction f7{ 0, 6 };
	f7.print();

	return 0;
}
