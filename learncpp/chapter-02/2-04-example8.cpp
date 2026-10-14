// 来源小节：2.4 Introduction to function parameters and arguments
// 示例说明：紧凑写法 —— 直接把 getValueFromUser() 的返回值作为实参传给 printDouble()，
//           省掉中间的临时变量 num。
//           预期交互（用户输入 4）：
//           Enter an integer: 4
//           4 doubled is: 8
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-function-parameters-and-arguments/
//
// 编译：g++ -std=c++20 -Wall 2-04-example8.cpp -o a

#include <iostream>

int getValueFromUser()
{
 	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;

	return input;
}

void printDouble(int value)
{
    std::cout << value << " doubled is: " << value * 2 << '\n';
}

int main()
{
    printDouble(getValueFromUser()); // use the return value of getValueFromUser() as an argument

    return 0;
}
