// 来源小节：4.5 Unsigned integers, and why to avoid them
// 示例说明：混用无符号与有符号做减法。有符号操作数被转换成无符号，结果也是无符号。
//           原文输出：4294967295
// 原文链接：https://www.learncpp.com/cpp-tutorial/unsigned-integers-and-why-to-avoid-them/
//
// 编译：g++ -std=c++20 -Wall 4-05-example5.cpp -o a

#include <iostream>

// assume int is 4 bytes
int main()
{
	unsigned int u{ 2 };
	signed int s{ 3 };

	std::cout << u - s << '\n'; // 2 - 3 = 4294967295

	return 0;
}
