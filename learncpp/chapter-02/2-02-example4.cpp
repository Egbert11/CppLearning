// 来源小节：2.2 Function return values (value-returning functions)
// 示例说明：修正版 —— getValueFromUser() 改为返回 int（用 return 把输入送回调用者），
//           main() 用它的返回值初始化 num。
//           预期交互（用户输入 4）：
//           Enter an integer: 4
//           4 doubled is: 8
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-return-values-value-returning-functions/
//
// 编译：g++ -std=c++20 -Wall 2-02-example4.cpp -o a

#include <iostream>

int getValueFromUser() // this function now returns an integer value
{
 	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;

	return input; // return the value the user entered back to the caller
}

int main()
{
	int num { getValueFromUser() }; // initialize num with the return value of getValueFromUser()

	std::cout << num << " doubled is: " << num * 2 << '\n';

	return 0;
}
