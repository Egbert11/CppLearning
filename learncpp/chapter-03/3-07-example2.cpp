// 来源小节：3.7 Using an integrated debugger: Running and breakpoints
// 示例说明：三次调用版本。断点设在同一行上时，会"该行执行几次就停下几次"；
//           而 Run to cursor 每次调用只停一次。本程序也用于演示 Set next statement 的向前/向后跳转。
// 在调试器中单步运行观察：
//   向前跳——运行到 printValue(6); 那一行后，把下一条语句设为它后面一行，输出为 5 \n 7。
//   向后跳——运行到调用完成之后，把下一条语句设回 printValue(6); 那一行，输出为 5 \n 6 \n 6 \n 7。
// 原文链接：https://www.learncpp.com/cpp-tutorial/using-an-integrated-debugger-running-and-breakpoints/
//
// 正常运行的预期输出：
//   5
//   6
//   7

#include <iostream>

void printValue(int value)
{
	std::cout << value << '\n';
}

int main()
{
	printValue(5);
	printValue(6);
	printValue(7);

	return 0;
}
