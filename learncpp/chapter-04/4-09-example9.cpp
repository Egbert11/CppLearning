// 来源小节：4.9 Boolean values
// 示例说明：为输入打开 std::boolalpha，使 cin 可以读入 true / false（区分大小写）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/boolean-values/
// 注意：此模式下只接受小写 true / false，数字 0/1 会被拒绝。

#include <iostream>

int main()
{
	bool b{};
	std::cout << "Enter a boolean value: ";

	// Allow the user to input 'true' or 'false' for boolean values
	// This is case-sensitive, so True or TRUE will not work
	std::cin >> std::boolalpha;
	std::cin >> b;

	// Let's also output bool values as `true` or `false`
	std::cout << std::boolalpha;
	std::cout << "You entered: " << b << '\n';

	return 0;
}
