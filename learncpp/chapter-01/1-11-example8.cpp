// 来源小节：1.11 Developing your first program
// 示例说明：“最佳”的方案——把表达式 num * 2 直接放进输出语句，num 本身保持不变。
// 原文链接：https://www.learncpp.com/cpp-tutorial/developing-your-first-program/
//
// 编译：g++ -std=c++20 -Wall 1-11-example8.cpp -o example8

#include <iostream>

// preferred version
int main()
{
	std::cout << "Enter an integer: ";

	int num{ };
	std::cin >> num;

	std::cout << "Double that number is: " <<  num * 2 << '\n'; // use an expression to multiply num * 2 at the point where we are going to print it

	return 0;
}
