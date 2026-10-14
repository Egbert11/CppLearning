// 来源小节：4.6 Fixed-width integers and size_t
// 示例说明：打印 least 与 fast 类型的实际尺寸（乘以 8 得到位数）。
//           原文在作者 Visual Studio 32 位控制台程序上的输出（随架构而异）：
//             least 8:  8 bits
//             least 16: 16 bits
//             least 32: 32 bits
//
//             fast 8:  8 bits
//             fast 16: 32 bits
//             fast 32: 32 bits
//           注意：fast/least 类型的尺寸由实现定义，输出依架构而定。
// 原文链接：https://www.learncpp.com/cpp-tutorial/fixed-width-integers-and-size-t/
//
// 编译：g++ -std=c++20 -Wall 4-06-example4.cpp -o a

#include <cstdint> // for fast and least types
#include <iostream>

int main()
{
	std::cout << "least 8:  " << sizeof(std::int_least8_t)  * 8 << " bits\n";
	std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
	std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
	std::cout << '\n';
	std::cout << "fast 8:  "  << sizeof(std::int_fast8_t)   * 8 << " bits\n";
	std::cout << "fast 16: "  << sizeof(std::int_fast16_t)  * 8 << " bits\n";
	std::cout << "fast 32: "  << sizeof(std::int_fast32_t)  * 8 << " bits\n";

	return 0;
}
