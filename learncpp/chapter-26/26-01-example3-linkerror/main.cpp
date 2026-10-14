// ============================================================
// 来源小节：26.1 Template classes（原 Example 6 的 main.cpp）
// 示例说明：与 example2 的 main 完全相同，但因为 operator[] 的定义被移到了
//           另一个翻译单元 Array.cpp 且未被实例化，链接时会报未定义引用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/template-classes/
// 构建（预期失败）：
//   g++ -std=c++20 -Wall 26-01-example3-linkerror/*.cpp -o example3
// 链接错误（GCC 原文）：
//   undefined reference to `Array<int>::operator[](int)'
//   以及 double 版本。本目录故意保留为可编译、但预期链接失败，勿修复。
// 备注：代码取自原文 HTML 逐字抽取。
// ============================================================
#include <iostream>
#include "Array.h"

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
