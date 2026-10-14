// 来源小节：4.9 Boolean values
// 示例说明：拷贝初始化允许 int→bool 的隐式转换（0 为 false，非 0 为 true）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/boolean-values/
// 预期输出：
//   true
//   false
// 注意：原文指出 bool b1 = 4; 可能产生警告；若编译器把警告当作错误，需临时关闭该选项。

#include <iostream>

int main()
{
	std::cout << std::boolalpha; // print bools as true or false

	bool b1 = 4; // copy initialization allows implicit conversion from int to bool
	std::cout << b1 << '\n';

	bool b2 = 0; // copy initialization allows implicit conversion from int to bool
	std::cout << b2 << '\n';

	return 0;
}
