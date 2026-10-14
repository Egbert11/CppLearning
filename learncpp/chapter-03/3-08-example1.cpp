// 来源小节：3.8 Using an integrated debugger: Watching variables
// 示例说明：程序把 x 依次赋值为 1、3、6 并输出。请在调试器里用 Run to cursor 分别停到
//           三条输出语句处，观察监视窗口 / 悬停中 x 的值从 1 变到 3 再变到 6。
// 在调试器中单步运行观察：Run to cursor 到第 6 行时 x == 1；到第 9 行时 x == 3；到第 12 行时 x == 6。
// 原文链接：https://www.learncpp.com/cpp-tutorial/using-an-integrated-debugger-watching-variables/
//
// 预期输出：
//   1 3 6

#include <iostream>

int main()
{
	int x{ 1 };
	std::cout << x << ' ';

	x = x + 2;
	std::cout << x << ' ';

	x = x + 3;
	std::cout << x << ' ';

	return 0;
}
