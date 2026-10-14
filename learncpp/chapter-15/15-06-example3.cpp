// ============================================================
// 来源小节：15.6 Static member variables
// 示例说明：静态成员变量被类的所有对象共享，只有一份实例。类内声明
//           static int s_value; 只是"声明"，还需在全局作用域给出定义。
//           修改 first.s_value 会同时影响 second.s_value。
// 原文链接：https://www.learncpp.com/cpp-tutorial/static-member-variables/
// 预期输出：2 然后 2
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

struct Something
{
	static int s_value; // 类内的静态成员变量声明
};

int Something::s_value{ 1 }; // 静态成员变量的定义（并初始化）

int main()
{
	Something first{};
	Something second{};

	first.s_value = 2;

	std::cout << first.s_value << '\n';  // 2
	std::cout << second.s_value << '\n'; // 2 —— 共享同一份

	return 0;
}
