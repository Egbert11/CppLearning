// ---------------------------------------------------------------------------
// 来源小节：25.x Chapter 25 summary and quiz（官方编号 25.x，本仓库顺延为 25.12）
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-25-summary-and-quiz/
// 测验题：Q1b —— 指出缺陷。
// 缺陷：Base::getName() 是虚函数但非 const，Derived::getName() 是 const，
//       两者签名不同，因此 Derived 的不是重写（override），通过 Base& 调用得到 Base::getName()。
// 实际输出：Base
// 命名后缀：-broken（能编译，但输出错误）。
// 代码为原文逐字提取。
// ---------------------------------------------------------------------------

#include <iostream>

class Base
{
protected:
	int m_value;

public:
	Base(int value)
		: m_value{ value }
	{
	}

	virtual const char* getName() { return "Base"; }
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base{ value }
	{
	}

	virtual const char* getName() const { return "Derived"; }
};

int main()
{
	Derived d{ 5 };
	Base& b{ d };
	std::cout << b.getName() << '\n';

	return 0;
}
