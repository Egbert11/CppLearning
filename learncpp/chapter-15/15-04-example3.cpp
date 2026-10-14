// ============================================================
// 来源小节：15.4 Introduction to destructors
// 示例说明：析构函数在对象被销毁时自动调用。块作用域对象在右花括号处
//           销毁（simple2 先于 simple1），函数作用域对象在 main() 结束时销毁。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-destructors/
// 预期输出：
//   Constructing Simple 1
//   Constructing Simple 2
//   Destructing Simple 2
//   Destructing Simple 1
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

class Simple
{
private:
	int m_id{};

public:
	Simple(int id)
		: m_id{ id }
	{
		std::cout << "Constructing Simple " << m_id << '\n';
	}

	~Simple() // here's our destructor
	{
		std::cout << "Destructing Simple " << m_id << '\n';
	}

	int getID() const { return m_id; }
};

int main()
{
	// 分配一个 Simple
	Simple simple1{ 1 };
	{
		Simple simple2{ 2 };
	} // simple2 在这里销毁

	return 0;
} // simple1 在这里销毁
