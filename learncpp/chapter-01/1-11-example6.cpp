// 来源小节：1.11 Developing your first program
// 示例说明：“不好”的方案——用 num = num * 2 重新赋值，破坏了原始输入，之后无法再用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/developing-your-first-program/
//
// 编译：g++ -std=c++20 -Wall 1-11-example6.cpp -o example6

#include <iostream>

// worst version
int main()
{
	std::cout << "Enter an integer: ";

	int num{ };
	std::cin >> num;

	num = num * 2; // double num's value, then assign that value back to num

	std::cout << "Double that number is: " << num << '\n';

	return 0;
}
