// 来源小节：27.7 Function try blocks
// 示例说明：把 try 关键字放在成员初始化列表之前，为整个构造函数建立函数级 try 块；
//           这样基类 A 构造函数在初始化列表中抛出的异常就会落到 B 的函数级 catch 里。
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
		if (x <= 0)
			throw 1; // Exception thrown here
	}
};

class B : public A
{
public:
	B(int x) try : A{x} // note addition of try keyword here
	{
	}
	catch (...) // note this is at same level of indentation as the function itself
	{
                // Exceptions from member initializer list or
                // from constructor body are caught here

                std::cerr << "Exception caught\n";

                throw; // rethrow the existing exception
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
