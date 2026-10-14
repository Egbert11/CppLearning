// 来源小节：4.12 Introduction to type conversion and static_cast
// 示例说明：Quiz #2 解法 (b)——返回时发生隐式转换。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-type-conversion-and-static_cast/

#include <iostream>

int charAsInt(char c)
{
	return c;
}

int main()
{
	std::cout << "Enter a single character: ";
	char c{};
	std::cin >> c;

	std::cout << "You entered '" << c << "', which has ASCII code " << charAsInt(c) << ".\n";

	return 0;
}
