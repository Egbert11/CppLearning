// 来源小节：4.5 Unsigned integers, and why to avoid them
// 示例说明：小的无符号数减去大的无符号数。真实结果 -1 无法用无符号表示，于是回绕。
//           原文输出：4294967295
// 原文链接：https://www.learncpp.com/cpp-tutorial/unsigned-integers-and-why-to-avoid-them/
//
// 编译：g++ -std=c++20 -Wall 4-05-example4.cpp -o a

#include <iostream>

// assume int is 4 bytes
int main()
{
	unsigned int x{ 2 };
	unsigned int y{ 3 };

	std::cout << x - y << '\n'; // prints 4294967295 (incorrect!)

	return 0;
}
