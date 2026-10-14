// ============================================================
// 来源小节：15.6 Static member variables
// 示例说明：在类内初始化的三种方式之一——静态 const 整型（含 char、bool）
//           与 const 枚举是编译期常量，可以直接在类内定义并初始化，
//           无需额外的类外定义。
// 原文链接：https://www.learncpp.com/cpp-tutorial/static-member-variables/
// 预期输出：4
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

class Whatever
{
public:
	static const int s_value{ 4 }; // 静态 const int 可直接在类内定义并初始化
};

int main()
{
	std::cout << Whatever::s_value << '\n';

	return 0;
}
