// ---------------------------------------------------------------------------
// 来源小节：25.x Chapter 25 summary and quiz（官方编号 25.x，本仓库顺延为 25.12）
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-25-summary-and-quiz/
// 测验题：Q1d —— 指出缺陷。
// 缺陷：Base 被声明为 final，不能作为基类被继承。
// 预期错误：error: cannot derive from 'final' base 'Base' in derived type 'Derived'。
//           编译命令：g++ -std=c++20 -Wall 25-12-quiz1d-error.cpp
//           该文件按设计无法编译，请勿修复。
// 代码为原文逐字提取。
// ---------------------------------------------------------------------------

#include <iostream>

class Base final
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
	Base& b{ d };
	std::cout << b.getName() << '\n';

	return 0;
}
