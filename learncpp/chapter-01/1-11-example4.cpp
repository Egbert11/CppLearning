// 来源小节：1.11 Developing your first program
// 示例说明：出错的版本——误用 std::cin << num。原文中此程序编译失败，报错类似：
//           error C2678: binary '<<': no operator found which takes a left-hand
//           operand of type 'std::istream'（std::cin 的类型即 std::istream）。
//           为让本文件仍可编译，出错的那一行以注释保留。
// 原文链接：https://www.learncpp.com/cpp-tutorial/developing-your-first-program/
//
// 编译：g++ -std=c++20 -Wall 1-11-example4.cpp -o example4

#include <iostream>

int main() // note: this program has an error somewhere
{
	std::cout << "Enter an integer: ";

	int num{ }; // define variable num as an integer variable
	// std::cin << num; // get integer value from user's keyboard
	// --- 上面这一行在原文中会编译失败：cin 必须用 operator>>，不能用 operator<<。---

	// 为避免未使用变量警告，这里用 >>
	std::cin >> num;

	return 0;
}
