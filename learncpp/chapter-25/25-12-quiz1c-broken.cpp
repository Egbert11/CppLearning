// ---------------------------------------------------------------------------
// 来源小节：25.x Chapter 25 summary and quiz（官方编号 25.x，本仓库顺延为 25.12）
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-25-summary-and-quiz/
// 测验题：Q1c —— 指出缺陷。
// 缺陷：override 是对的，但 `Base b{ d };` 把 Derived 对象按值拷贝进 Base 对象，
//       发生了对象切片，Derived 部分丢失，打印 Base::getName()。
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

	const char* getName() override { return "Derived"; }
};

int main()
{
	Derived d{ 5 };
	Base b{ d };
	std::cout << b.getName() << '\n';

	return 0;
}
