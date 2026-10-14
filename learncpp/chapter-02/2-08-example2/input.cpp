// 来源小节：2.8 Programs with multiple code files（课后测验）
// 示例说明：getInteger() 的定义所在文件。由于本文件也使用 std::cout / std::cin，
//           所以它必须自己 #include <iostream>（每个 .cpp 文件独立编译）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/programs-with-multiple-code-files/

#include <iostream> // we need iostream since we use it in this file

int getInteger()
{
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;
	return x;
}
