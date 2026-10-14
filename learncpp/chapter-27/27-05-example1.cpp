// ============================================================
// 来源小节：27.5 Exceptions, classes, and inheritance
// 示例说明：构造函数抛出异常时的清理行为。A 的构造函数在 x <= 0 时 throw 1，
//           于是 A 自身的析构函数不会被调用（对象从未构造完成），但已经构造
//           完成的成员 m_member 仍会被正常析构——所以应把资源交给成员对象管理
//           （RAII），而不是直接在构造函数体里手动分配。
// 原文链接：https://www.learncpp.com/cpp-tutorial/exceptions-classes-and-inheritance/
// 预期输出：
//   Member allocated some resources
//   Member cleaned up
//   Oops
// 备注：本示例逐字取自原文（含 main）。
// ============================================================
#include <iostream>

class Member
{
public:
	Member()
	{
		std::cerr << "Member allocated some resources\n";
	}

	~Member()
	{
		std::cerr << "Member cleaned up\n";
	}
};

class A
{
private:
	int m_x {};
	Member m_member;

public:
	A(int x) : m_x{x}
	{
		if (x <= 0)
			throw 1;
	}

	~A()
	{
		std::cerr << "~A\n"; // should not be called
	}
};


int main()
{
	try
	{
		A a{0};
	}
	catch (int)
	{
		std::cerr << "Oops\n";
	}

	return 0;
}
