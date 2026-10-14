// ============================================================
// 来源小节：26.1 Template classes（原 Example 8 的 templates.cpp）
// 示例说明：三文件方案的“胶水文件”。它同时包含头文件与 .cpp 文件，再用
//           `template class Array<int>;` 之类的命令为需要的类型显式实例化。
//           这与 example3 的输出相同，但能正常链接。
// 原文链接：https://www.learncpp.com/cpp-tutorial/template-classes/
// 构建：g++ -std=c++20 -Wall 26-01-example4/templates.cpp -o example4
//       （只编译 templates.cpp，不要 glob 整个目录，否则 Array.cpp 会被重复编译）
// 预期输出：与 26-01-example2 相同（11 11.5 ... 0 0.5，制表符分隔）。
// 备注：代码取自原文 HTML 逐字抽取。
// ============================================================
// Ensure the full Array template definition can be seen
#include "Array.h"
#include "Array.cpp" // we're breaking best practices here, but only in this one place

// #include other .h and .cpp template definitions you need here

template class Array<int>; // Explicitly instantiate template Array<int>
template class Array<double>; // Explicitly instantiate template Array<double>

// instantiate other templates here

#include <iostream>

int main()
{
	const int length { 12 };
	Array<int> intArray { length };
	Array<double> doubleArray { length };

	for (int count{ 0 }; count < length; ++count)
	{
		intArray[count] = count;
		doubleArray[count] = count + 0.5;
	}

	for (int count{ length - 1 }; count >= 0; --count)
		std::cout << intArray[count] << '\t' << doubleArray[count] << '\n';

	return 0;
}
