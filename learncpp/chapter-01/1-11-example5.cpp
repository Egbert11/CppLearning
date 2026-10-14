// 来源小节：1.11 Developing your first program
// 示例说明：修正版——用 std::cin >> num 正确读取用户输入。
// 原文链接：https://www.learncpp.com/cpp-tutorial/developing-your-first-program/
//
// 编译：g++ -std=c++20 -Wall 1-11-example5.cpp -o example5

#include <iostream>

int main()
{
	std::cout << "Enter an integer: ";

	int num{ };
	std::cin >> num; // std::cin uses operator >>, not operator <<!

	return 0;
}
