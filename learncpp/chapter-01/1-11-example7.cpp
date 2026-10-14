// 来源小节：1.11 Developing your first program
// 示例说明：“较好”的方案——新建 doublenum 变量存放 num * 2 后打印。
// 原文链接：https://www.learncpp.com/cpp-tutorial/developing-your-first-program/
//
// 编译：g++ -std=c++20 -Wall 1-11-example7.cpp -o example7

#include <iostream>

// less-bad version
int main()
{
	std::cout << "Enter an integer: ";

	int num{ };
	std::cin >> num;

	int doublenum{ num * 2 }; // define a new variable and initialize it with num * 2
	std::cout << "Double that number is: " << doublenum << '\n'; // then print the value of that variable here

	return 0;
}
