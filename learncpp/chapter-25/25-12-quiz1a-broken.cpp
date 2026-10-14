// ---------------------------------------------------------------------------
// 来源小节：25.x Chapter 25 summary and quiz（官方编号 25.x，本仓库顺延为 25.12）
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-25-summary-and-quiz/
// 测验题：Q1a —— 下列程序有缺陷，请指出（不要编译）。程序本意是打印 "Derived"。
// 缺陷：Base::getName() 不是虚函数，通过 Base& 调用的是 Base::getName()。
// 实际输出：Base
// 命名后缀：-broken（能编译，但输出错误，是教学用的「缺陷」示例）。
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

	const char* getName() const { return "Base"; }
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base{ value }
	{
	}

	const char* getName() const { return "Derived"; }
};

int main()
{
	Derived d{ 5 };
	Base& b{ d };
	std::cout << b.getName() << '\n';

	return 0;
}
