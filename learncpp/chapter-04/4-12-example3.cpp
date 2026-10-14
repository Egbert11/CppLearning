// 来源小节：4.12 Introduction to type conversion and static_cast
// 示例说明：隐式窄化——把 double 值 5.5 传给 int 形参，会丢弃小数部分并产生警告。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-type-conversion-and-static_cast/
// 预期输出：5
// 注意：本示例**故意演示警告**：若编译器把警告当作错误，需临时关闭该选项才能编译。

#include <iostream>

void print(int x) // print now takes an int parameter
{
	std::cout << x << '\n';
}

int main()
{
	print(5.5); // warning: we're passing in a double value

	return 0;
}
