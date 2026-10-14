// ---------------------------------------------------------------------------
// 来源小节：25.11 Printing inherited classes using operator<<
// 原文链接：https://www.learncpp.com/cpp-tutorial/printing-inherited-classes-using-operator/
// 示例说明：解决方案一——operator<< 只做 Base 的友元，它调用一个普通的虚成员函数
//           identify()（返回要打印的字符串），由虚函数决定输出内容。无需为每个
//           派生类都写 operator<<。
// 预期输出：
//   Base
//   Derived
//   Derived
// 代码为原文逐字提取（原文示例未显式列出 <string>/#include，此处补上以便编译）。
// ---------------------------------------------------------------------------

#include <iostream>
#include <string>

class Base
{
public:
	// Here's our overloaded operator<<
	friend std::ostream& operator<<(std::ostream& out, const Base& b)
	{
		// Call virtual function identify() to get the string to be printed
		out << b.identify();
		return out;
	}

	// We'll rely on member function identify() to return the string to be printed
	// Because identify() is a normal member function, it can be virtualized
	virtual std::string identify() const
	{
		return "Base";
	}
};

class Derived : public Base
{
public:
	// Here's our override identify() function to handle the Derived case
	std::string identify() const override
	{
		return "Derived";
	}
};

int main()
{
	Base b{};
	std::cout << b << '\n';

	Derived d{};
	std::cout << d << '\n'; // note that this works even with no operator<< that explicitly handles Derived objects

	Base& bref{ d };
	std::cout << bref << '\n';

	return 0;
}
