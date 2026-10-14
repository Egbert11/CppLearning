// 来源小节：2.2 Function return values (value-returning functions)
// 示例说明：最初的程序，全部逻辑写在 main() 里：读入一个整数并打印它的两倍。
//           预期交互（用户输入 4）：
//           Enter an integer: 4
//           4 doubled is: 8
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-return-values-value-returning-functions/
//
// 编译：g++ -std=c++20 -Wall 2-02-example1.cpp -o a

#include <iostream>

int main()
{
	// First, read an integer value from the user
	std::cout << "Enter an integer: ";
	int num{};
	std::cin >> num;

	// Then, print that value doubled
	std::cout << num << " doubled is: " << num * 2 << '\n';

	return 0;
}
