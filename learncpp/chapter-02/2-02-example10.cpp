// 来源小节：2.2 Function return values (value-returning functions)
// 示例说明：复用函数消除重复 —— 用 getValueFromUser() 的返回值两次初始化 x、y。
//           预期交互（用户先输入 5 再输入 7）：
//           Enter an integer: 5
//           Enter an integer: 7
//           5 + 7 = 12
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-return-values-value-returning-functions/
//
// 编译：g++ -std=c++20 -Wall 2-02-example10.cpp -o a

#include <iostream>

int getValueFromUser()
{
 	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;

	return input;
}

int main()
{
    int x{ getValueFromUser() }; // first call to getValueFromUser
    int y{ getValueFromUser() }; // second call to getValueFromUser

    std::cout << x << " + " << y << " = " << x + y << '\n';

    return 0;
}
