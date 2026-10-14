// 来源小节：3.6 Using an integrated debugger: Stepping
// 示例说明：用 std::unitbuf 让 std::cout 立即刷新，这样调试时输出会马上出现（而不是等到缓冲被填满）。
//           调试结束后应及时移除或注释掉这一行，以免影响性能。
// 在调试器中单步运行观察：输出会立即出现在控制台。
// 原文链接：https://www.learncpp.com/cpp-tutorial/using-an-integrated-debugger-stepping/
//
// 预期输出：
//   Hello, debugger!

#include <iostream>

int main()
{
	// 无条件版本：调试期间临时放在 main() 开头
	std::cout << std::unitbuf; // enable automatic flushing for std::cout (for debugging)

	// 另一种写法：只在定义了 DEBUG 宏时启用（可把该宏定义在此行上方，或在编译器设置中定义）
	// #ifdef DEBUG
	// std::cout << std::unitbuf; // enable automatic flushing for std::cout (for debugging)
	// #endif

	std::cout << "Hello, debugger!\n";

	return 0;
}
