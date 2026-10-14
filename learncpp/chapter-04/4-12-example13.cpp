// 来源小节：4.12 Introduction to type conversion and static_cast
// 示例说明：Quiz #1 解法——读取一个字符并打印它及其 ASCII 码（用 static_cast）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-type-conversion-and-static_cast/

#include <iostream>

int main()
{
	std::cout << "Enter a single character: ";
	char c{};
	std::cin >> c;
	std::cout << "You entered '" << c << "', which has ASCII code " << static_cast<int>(c) << ".\n";

	return 0;
}
