// ============================================================
// 来源小节：15.6 Static member variables
// 示例说明：C++17 起，静态成员可以是 inline 变量，于是无论是否为常量，
//           都能直接在类内定义并初始化（本节推荐的写法）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/static-member-variables/
// 预期输出：4
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

class Whatever
{
public:
	static inline int s_value{ 4 }; // 静态 inline 变量可直接在类内定义并初始化
};

int main()
{
	std::cout << Whatever::s_value << '\n';

	return 0;
}
