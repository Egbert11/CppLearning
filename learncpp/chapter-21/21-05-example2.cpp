// 来源小节：21.5 Overloading operators using member functions
// 示例说明：把同一个运算符改写为成员函数。三步转换：改为成员、删掉左参数（它变成
//           隐式 *this）、去掉函数体里对左参数的引用。调用写法不变。
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
    Cents operator+(int value) const;

    int getCents() const { return m_cents; }
};

// note: this function is a member function!
// the cents parameter in the friend version is now the implicit *this parameter
Cents Cents::operator+ (int value) const
{
    return Cents { m_cents + value };
}

int main()
{
	const Cents cents1 { 6 };
	const Cents cents2 { cents1 + 2 };
	std::cout << "I have " << cents2.getCents() << " cents.\n";

	return 0;
}
