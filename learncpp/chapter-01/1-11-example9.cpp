// 来源小节：1.11 Developing your first program
// 示例说明：测验解答——同时打印双倍数与三倍数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/developing-your-first-program/
//
// 预期输出（输入 4）：
//   Enter an integer: 4
//   Double 4 is: 8
//   Triple 4 is: 12
//
// 编译：g++ -std=c++20 -Wall 1-11-example9.cpp -o example9

#include <iostream>

int main()
{
	std::cout << "Enter an integer: ";

	int num{ };
	std::cin >> num;

	std::cout << "Double " << num << " is: " << num * 2 << '\n';
	std::cout << "Triple " << num << " is: " << num * 3 << '\n';

	return 0;
}
