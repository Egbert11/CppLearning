// 来源小节：7.11 Static local variables
// 示例说明：用静态局部变量 s_isFirstCall 改变输出：首次调用提示 "Enter an integer: "，
//           之后提示 "Enter another integer: "。能工作，但隐藏状态令函数难以理解和复用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/static-local-variables/
//
// 本节示例为按原文描述重建（对应原文 Example 4）。需交互输入。
// 示例输出（输入 5 与 9 时）：
// Enter an integer: 5
// Enter another integer: 9
// 5 + 9 = 14

#include <iostream>

int getInteger()
{
	static bool s_isFirstCall{ true };

	if (s_isFirstCall)
	{
		std::cout << "Enter an integer: ";
		s_isFirstCall = false;
	}
	else
	{
		std::cout << "Enter another integer: ";
	}

	int i{};
	std::cin >> i;
	return i;
}

int main()
{
	int a{ getInteger() };
	int b{ getInteger() };

	std::cout << a << " + " << b << " = " << (a + b) << '\n';

	return 0;
}
