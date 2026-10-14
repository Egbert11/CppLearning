// ============================================================
// 来源小节：15.6 Static member variables
// 示例说明：静态 constexpr 成员自 C++17 起隐式 inline，因此可在类内初始化，
//           无需写 inline；这适用于任何支持 constexpr 初始化的类型
//           （例如 constexpr 的 std::string_view）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/static-member-variables/
// 预期输出：2.2 与 Hello
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <string_view>

class Whatever
{
public:
	static constexpr double s_value{ 2.2 };            // ok
	static constexpr std::string_view s_view{ "Hello" }; // C++17 起也可行
};

int main()
{
	std::cout << Whatever::s_value << '\n';
	std::cout << Whatever::s_view << '\n';

	return 0;
}
