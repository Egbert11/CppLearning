// ---------------------------------------------------------------------------
// 来源小节：25.11 Printing inherited classes using operator<<
// 原文链接：https://www.learncpp.com/cpp-tutorial/printing-inherited-classes-using-operator/
// 示例说明：用成员函数 print() 打印时无法与 std::cout 的 << 串联，必须把一条输出语句拆开——很别扭。
// 预期输出：b is a Derived
// 原文该例的 main() 为逐字提取；Base/Derived 定义取自原文 Example 1。
// ---------------------------------------------------------------------------

#include <iostream>

class Base
{
public:
	virtual void print() const { std::cout << "Base";  }
};

class Derived : public Base
{
public:
	void print() const override { std::cout << "Derived"; }
};

// --- 原文示例片段 ---
int main()
{
	Derived d{};
	Base& b{ d };

	std::cout << "b is a ";
	b.print(); // messy, we have to break our print statement to call this function
	std::cout << '\n';

	return 0;
}
