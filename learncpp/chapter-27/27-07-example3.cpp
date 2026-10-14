// 来源小节：27.7 Function try blocks
// 示例说明：把抛出异常的代码从 A 的构造函数移到 B 的构造函数体内，A 构造函数不再抛出；
//           证明函数级 try 块同样能捕获"当前类"构造函数体内抛出的异常。
//           若 catch 中不显式 throw，当前异常会在函数级 catch 末尾被隐式重新抛出。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-try-blocks/
// 预期输出：
//   Exception caught
//   Oops

#include <iostream>

class A
{
private:
	int m_x;
public:
	A(int x) : m_x{x}
	{
	}
};

class B : public A
{
public:
	B(int x) try : A{x} // note addition of try keyword here
	{
		if (x <= 0) // moved this from A to B
			throw 1; // and this too
	}
	catch (...)
	{
                std::cerr << "Exception caught\n";

                // If an exception isn't explicitly thrown here,
                // the current exception will be implicitly rethrown
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
