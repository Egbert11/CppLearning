// 来源小节：4.12 Introduction to type conversion and static_cast
// 示例说明：隐式转换——把 int 字面量 5 传给 double 形参，编译器自动转换。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-type-conversion-and-static_cast/
// 预期输出：5

#include <iostream>

void print(double x) // print takes a double parameter
{
	std::cout << x << '\n';
}

int main()
{
	print(5); // what happens when we pass an int value?

	return 0;
}
