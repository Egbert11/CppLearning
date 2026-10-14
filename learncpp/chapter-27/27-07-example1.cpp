// 来源小节：27.7 Function try blocks
// 示例说明：问题演示——B 的构造函数在成员初始化列表里构造基类 A，而 A 的构造函数抛出异常；
//           普通的 try 块无法包住成员初始化列表，所以只能在 main 里捕获。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-try-blocks/
// 预期输出：Oops

#include <iostream>

class A
{
private:
	int m_x;
public:
	A(int x) : m_x{x}
	{
		if (x <= 0)
			throw 1; // Exception thrown here
	}
};

class B : public A
{
public:
	B(int x) : A{x} // A initialized in member initializer list of B
	{
		// What happens if creation of A fails and we want to handle it here?
	}
};

int main()
{
	try
	{
		B b{0};
	}
	catch (int)
	{
		std::cout << "Oops\n";
	}
}
