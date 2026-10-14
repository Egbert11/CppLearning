// 来源小节：3.9 Using an integrated debugger: The call stack
// 示例说明：嵌套调用的程序，用于在调试器的"调用栈"窗口中观察栈帧随调用/返回的变化。
//           在第 5 行（a() 的打印语句）与第 10 行（b() 的打印语句）各设一个断点，然后开始调试：
//             第一次停在 a()（因为 main 先调用 a）；继续 → 停在 b()；继续 → 再次停在 a()（因为 b 调用 a）。
// 在调试器中单步运行观察：调用栈自下而上依次出现 main、b、a 等帧。
// 原文链接：https://www.learncpp.com/cpp-tutorial/using-an-integrated-debugger-the-call-stack/
//
// 预期输出：
//   a() called
//   b() called
//   a() called

#include <iostream>

void a()
{
	std::cout << "a() called\n"; // 第 5 行：第一个断点
}

void b()
{
	std::cout << "b() called\n"; // 第 10 行：第二个断点
	a();
}

int main()
{
	a();
	b();

	return 0;
}
