// ---------------------------------------------------------------------------
// 来源小节：25.11 Printing inherited classes using operator<<
// 原文链接：https://www.learncpp.com/cpp-tutorial/printing-inherited-classes-using-operator/
// 示例说明：通过基类引用调用虚函数 print() 会派发到派生类版本（b.print() 调用 Derived::print()）。
// 预期输出：Derived
// 代码为原文逐字提取。
// ---------------------------------------------------------------------------

#include <iostream>

class Base
{
public:
	virtual void print() const { std::cout << "Base";  }
};

class Derived : public Base
{
public:
	void print() const override { std::cout << "Derived"; }
};

int main()
{
	Derived d{};
	Base& b{ d };
	b.print(); // will call Derived::print()

	return 0;
}
