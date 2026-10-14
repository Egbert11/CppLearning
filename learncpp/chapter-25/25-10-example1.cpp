// ---------------------------------------------------------------------------
// 来源小节：25.10 Dynamic casting
// 原文链接：https://www.learncpp.com/cpp-tutorial/dynamic-casting/
// 示例说明：引出问题——手上只有 Base* 指针，却想访问只有 Derived 才有的数据。
//           C++ 允许派生类指针隐式转换为基类指针（upcasting）。
// 预期输出：无（程序本身不打印）。
// 代码为原文逐字提取。
// ---------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <string_view>

class Base
{
protected:
	int m_value{};

public:
	Base(int value)
		: m_value{value}
	{
	}

	virtual ~Base() = default;
};

class Derived : public Base
{
protected:
	std::string m_name{};

public:
	Derived(int value, std::string_view name)
		: Base{value}, m_name{name}
	{
	}

	const std::string& getName() const { return m_name; }
};

Base* getObject(bool returnDerived)
{
	if (returnDerived)
		return new Derived{1, "Apple"};
	else
		return new Base{2};
}

int main()
{
	Base* b{ getObject(true) };

	// how do we print the Derived object's name here, having only a Base pointer?

	delete b;

	return 0;
}
