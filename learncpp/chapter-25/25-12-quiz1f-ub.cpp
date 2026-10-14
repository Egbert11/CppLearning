// ---------------------------------------------------------------------------
// 来源小节：25.x Chapter 25 summary and quiz（官方编号 25.x，本仓库顺延为 25.12）
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-25-summary-and-quiz/
// 测验题：Q1f —— 指出缺陷。
// 缺陷：Base 有虚函数却没有虚析构函数；通过 Base* delete 派生对象时，
//       只调用 Base 的析构函数（派生类析构函数不会运行），属未定义行为。
// 命名后缀：-ub（可编译，运行结果依实现而定；本例 Derived 无成员，通常看不出异常，
//           但语义上已是 UB）。
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

	virtual const char* getName() { return "Derived"; }
};

int main()
{
	auto* d{ new Derived(5) };
	Base* b{ d };
	std::cout << b->getName() << '\n';
	delete b;

	return 0;
}
