// 来源小节：2.8 Programs with multiple code files（课后测验）
// 示例说明：把 getInteger() 拆分到 input.cpp 之后，main.cpp 仍需要 #include <iostream>
//           （因为它自己用了 std::cout），并给出 getInteger() 的前置声明。
// 原文链接：https://www.learncpp.com/cpp-tutorial/programs-with-multiple-code-files/
//
// 编译：g++ -std=c++20 -Wall 2-08-example2/main.cpp 2-08-example2/input.cpp -o main

#include <iostream> // we need iostream here too since we use it in this file as well

int getInteger(); // forward declaration for function getInteger

int main()
{
	int x{ getInteger() };
	int y{ getInteger() };

	std::cout << x << " + " << y << " is " << x + y << '\n';
	return 0;
}
