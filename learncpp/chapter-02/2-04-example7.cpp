// 来源小节：2.4 Introduction to function parameters and arguments
// 示例说明：修好的挑战程序 —— printDouble(int value) 通过参数 value 收到 main 中 num 的副本。
//           预期交互（用户输入 4）：
//           Enter an integer: 4
//           4 doubled is: 8
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-function-parameters-and-arguments/
//
// 编译：g++ -std=c++20 -Wall 2-04-example7.cpp -o a

#include <iostream>

int getValueFromUser()
{
 	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;

	return input;
}

void printDouble(int value) // this function now has a parameter named value
{
    std::cout << value << " doubled is: " << value * 2 << '\n';
}

int main()
{
    int num { getValueFromUser() };

    printDouble(num); // pass the value of num to printDouble()

    return 0;
}
