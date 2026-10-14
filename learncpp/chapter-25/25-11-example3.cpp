// ---------------------------------------------------------------------------
// 来源小节：25.11 Printing inherited classes using operator<<
// 原文链接：https://www.learncpp.com/cpp-tutorial/printing-inherited-classes-using-operator/
// 示例说明：朴素地为 Base 和 Derived 各写一个友元 operator<<，直接对象可以正常工作。
// 预期输出：
//   Base
//   Derived
// 代码为原文逐字提取。
// ---------------------------------------------------------------------------

#include <iostream>

class Base
{
public:
	virtual void print() const { std::cout << "Base"; }

	friend std::ostream& operator<<(std::ostream& out, const Base& b)
	{
		out << "Base";
		return out;
	}
};

class Derived : public Base
{
public:
	void print() const override { std::cout << "Derived"; }

	friend std::ostream& operator<<(std::ostream& out, const Derived& d)
	{
		out << "Derived";
		return out;
	}
};

int main()
{
	Base b{};
	std::cout << b << '\n';

	Derived d{};
	std::cout << d << '\n';

	return 0;
}
