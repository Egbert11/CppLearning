// ============================================================
// 来源小节：15.7 Static member functions
// 示例说明：用普通（非静态）公有成员函数作为访问函数读取私有静态成员。
//           这能工作，但必须创建一个对象才能调用它——为了读一个"属于类"的
//           值而被迫实例化对象，是它不方便的地方。
// 原文链接：https://www.learncpp.com/cpp-tutorial/static-member-functions/
// 预期输出：1
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

class Something
{
private:
	static inline int s_value { 1 };

public:
	int getValue() { return s_value; } // 非静态成员函数
};

int main()
{
	Something s{};                    // 必须先创建一个对象
	std::cout << s.getValue() << '\n'; // 才能通过它调用非静态访问函数
	return 0;
}
