// 来源小节：4.12 Introduction to type conversion and static_cast
// 示例说明：隐式转换——把 int 变量 y 传给 double 形参，y 本身仍为 int。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-type-conversion-and-static_cast/

#include <iostream>

void print(double x) // print takes a double parameter
{
	std::cout << x << '\n';
}

int main()
{
	int y { 5 };
	print(y); // y is of type int

	return 0;
}
