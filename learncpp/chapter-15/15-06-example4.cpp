// ============================================================
// 来源小节：15.6 Static member variables
// 示例说明：静态成员不属于任何对象，即使没有实例化也能访问。推荐用
//           "类名 + 作用域解析运算符 ::" 的方式访问。
// 原文链接：https://www.learncpp.com/cpp-tutorial/static-member-variables/
// 预期输出：2
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

class Something
{
public:
	static int s_value;
};

int Something::s_value{ 1 };

int main()
{
	Something::s_value = 2; // 通过类名访问，无需任何对象
	std::cout << Something::s_value << '\n';

	return 0;
}
