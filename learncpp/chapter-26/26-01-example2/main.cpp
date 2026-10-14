// ============================================================
// 来源小节：26.1 Template classes（原 Example 4 的 main.cpp）
// 示例说明：用模板类 Array<T> 同时创建 Array<int> 与 Array<double> 两个
//           “实例（instantiation）”，正向填充、反向打印。
// 原文链接：https://www.learncpp.com/cpp-tutorial/template-classes/
// 构建：g++ -std=c++20 -Wall 26-01-example2/*.cpp -o example2
// 预期输出（制表符分隔）：
//   11	11.5
//   10	10.5
//   ...（依次递减）
//   0	0.5
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
