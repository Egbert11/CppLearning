// ============================================================
// 来源小节：15.7 Static member functions
// 示例说明：公有静态成员变量可以直接用"类名 + :: "访问，无需创建任何对象。
// 原文链接：https://www.learncpp.com/cpp-tutorial/static-member-functions/
// 预期输出：1
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

class Something
{
public:
	static inline int s_value { 1 };
};

int main()
{
	std::cout << Something::s_value << '\n';
	return 0;
}
