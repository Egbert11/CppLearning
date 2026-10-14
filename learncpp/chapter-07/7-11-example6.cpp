// 来源小节：7.11 Static local variables
// 示例说明：把"是否首次调用"作为参数传入，函数不再持有隐藏状态，因而可复用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/static-local-variables/
//
// 本节示例为按原文描述重建（对应原文 Example 6）。需交互输入。
// 示例输出（输入 5 与 9 时）：
// Enter an integer: 5
// Enter another integer: 9
// 5 + 9 = 14

#include <iostream>

// 用一个名字清晰的符号常量
constexpr bool g_firstCall { true };

int getInteger(bool bFirstCall)
{
	if (bFirstCall)
	{
		std::cout << "Enter an integer: ";
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
	int a{ getInteger(g_firstCall) };  // 这样能让参数含义更清楚
	int b{ getInteger(!g_firstCall) };

	std::cout << a << " + " << b << " = " << (a + b) << '\n';

	return 0;
}
