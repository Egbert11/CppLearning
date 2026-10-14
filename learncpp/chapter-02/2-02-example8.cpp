// 来源小节：2.2 Function return values (value-returning functions)
// 示例说明：用注释说明返回值含义的好习惯 —— 明确写出“返回值是用户从键盘输入的整数”。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-return-values-value-returning-functions/
//
// 编译：g++ -std=c++20 -Wall 2-02-example8.cpp -o a

#include <iostream>

// Function asks user to enter a value
// Return value is the integer entered by the user from the keyboard
int getValueFromUser()
{
 	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;

	return input;
}

int main()
{
    std::cout << getValueFromUser() << '\n';
    return 0;
}
