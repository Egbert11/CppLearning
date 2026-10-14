// ---------------------------------------------------------------------------
// 来源小节：25.10 Dynamic casting
// 原文链接：https://www.learncpp.com/cpp-tutorial/dynamic-casting/
// 示例说明：对引用使用 dynamic_cast。因为 C++ 没有空引用，转换失败会抛出
//           std::bad_cast 异常（而不是返回空指针）。
// 预期输出：The name of the Derived is: Apple
// 代码为原文逐字提取。
// ---------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <string_view>

class Base
{
protected:
	int m_value;

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
	std::string m_name;

public:
	Derived(int value, std::string_view name)
		: Base{value}, m_name{name}
	{
	}

	const std::string& getName() const { return m_name; }
};

int main()
{
	Derived apple{1, "Apple"}; // create an apple
	Base& b{ apple }; // set base reference to object
	Derived& d{ dynamic_cast<Derived&>(b) }; // dynamic cast using a reference instead of a pointer

	std::cout << "The name of the Derived is: " << d.getName() << '\n'; // we can access Derived::getName through d

	return 0;
}
