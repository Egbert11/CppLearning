// 来源小节：4.12 Introduction to type conversion and static_cast
// 示例说明：用 static_cast 做显式转换，把 double 值 5.5 转成 int。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-type-conversion-and-static_cast/
// 输出：5

#include <iostream>

void print(int x)
{
	std::cout << x << '\n';
}

int main()
{
	print( static_cast<int>(5.5) ); // explicitly convert double value 5.5 to an int

	return 0;
}
