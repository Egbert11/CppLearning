// 来源小节：4.6 Fixed-width integers and size_t
// 示例说明：用 sizeof 测量 std::size_t 自身。原文在作者 32 位控制台程序上输出：4
// 原文链接：https://www.learncpp.com/cpp-tutorial/fixed-width-integers-and-size-t/
//
// 编译：g++ -std=c++20 -Wall 4-06-example8.cpp -o a

#include <cstddef> // for std::size_t
#include <iostream>

int main()
{
	std::cout << sizeof(std::size_t) << '\n';

	return 0;
}
