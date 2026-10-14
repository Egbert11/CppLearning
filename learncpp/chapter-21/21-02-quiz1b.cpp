// 来源小节：21.2 Overloading the arithmetic operators using friend functions
// 示例说明：测验 1b 解答——用友元函数重载乘法：Fraction*Fraction、Fraction*int、int*Fraction。
//           参数用 const 引用：既避免拷贝，又能接受右值（如临时 Fraction 对象）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-arithmetic-operators-using-friend-functions/
// 说明：本节代码取自原文（逐字保留）。此版本尚未约分。
// 预期输出：
//   2/5
//   3/8
//   6/40
//   4/5
//   6/8
//   6/24

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

	// We don't want to pass by value, because copying is slow.
	// We can't and shouldn't pass by non-const reference, because then
	// our functions wouldn't work with r-values.
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
	Fraction f1{2, 5};
	f1.print();

	Fraction f2{3, 8};
	f2.print();

	Fraction f3{ f1 * f2 };
	f3.print();

	Fraction f4{ f1 * 2 };
	f4.print();

	Fraction f5{ 2 * f2 };
	f5.print();

	Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
	f6.print();

	return 0;
}
