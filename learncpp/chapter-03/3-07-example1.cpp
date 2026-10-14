// 来源小节：3.7 Using an integrated debugger: Running and breakpoints
// 示例说明：单次调用程序，用于在调试器中练习 Run to cursor、Continue、Start 与断点。
//           例如把断点设到 printValue(5); 那一行，Start 后程序会停在那里。
// 在调试器中单步运行观察：程序最终打印 5。
// 原文链接：https://www.learncpp.com/cpp-tutorial/using-an-integrated-debugger-running-and-breakpoints/
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
