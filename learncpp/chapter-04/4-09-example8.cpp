// 来源小节：4.9 Boolean values
// 示例说明：std::cin 默认的布尔输入行为——只接受数字；输入 true 会得到 0（并进入失败模式）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/boolean-values/
// 示例交互：
//   Enter a boolean value: true
//   You entered: 0

#include <iostream>

int main()
{
	bool b{}; // default initialize to false
	std::cout << "Enter a boolean value: ";
	std::cin >> b;
	std::cout << "You entered: " << b << '\n';

	return 0;
}
