// 来源小节：3.6 Using an integrated debugger: Stepping
// 示例说明：双函数程序，用于在调试器中练习单步执行——
//           Step Into 会在 printValue(5) 处进入 printValue；Step Over 会跳过它；Step Out 会跑完它。
// 在调试器中单步运行观察：程序最终打印 5。
// 原文链接：https://www.learncpp.com/cpp-tutorial/using-an-integrated-debugger-stepping/
//
// 预期输出：
//   5

#include <iostream>

void printValue(int value)
{
	std::cout << value << '\n';
}

int main()
{
	printValue(5);

	return 0;
}
