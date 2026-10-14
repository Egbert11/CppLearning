// ---------------------------------------------------------------------------
// 来源小节：25.10 Dynamic casting
// 原文链接：https://www.learncpp.com/cpp-tutorial/dynamic-casting/
// 示例说明：手写类型标识——用虚函数 getClassID() 返回枚举验证类型，再用
//           static_cast 向下转换。若你已经付出了一次虚函数的代价，用
//           dynamic_cast 往往更简单。
// 预期输出：The name of the Derived is: Apple
// 代码为原文逐字提取。
// ---------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <string_view>

// Class identifier
enum class ClassID
{
	base,
	derived
	// Others can be added here later
};

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
	virtual ClassID getClassID() const { return ClassID::base; }
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
	ClassID getClassID() const override { return ClassID::derived; }

};

Base* getObject(bool bReturnDerived)
{
	if (bReturnDerived)
		return new Derived{1, "Apple"};
	else
		return new Base{2};
}

int main()
{
	Base* b{ getObject(true) };

	if (b->getClassID() == ClassID::derived)
	{
		// We already proved b is pointing to a Derived object, so this should always succeed
		Derived* d{ static_cast<Derived*>(b) };
		std::cout << "The name of the Derived is: " << d->getName() << '\n';
	}

	delete b;

	return 0;
}
