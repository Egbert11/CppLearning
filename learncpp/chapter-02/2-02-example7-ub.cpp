// 来源小节：2.2 Function return values (value-returning functions)
// 示例说明：未定义行为(UB) —— getValueFromUserUB() 声明返回 int，却没有任何 return 语句。
//           现代编译器（g++ -Wall）会给出警告，如：
//           warning: control reaches end of non-void function [-Wreturn-type]
//           运行结果不可预测，属未定义行为。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-return-values-value-returning-functions/
//
// 编译：g++ -std=c++20 -Wall 2-02-example7-ub.cpp -o a   （应出现 -Wreturn-type 警告）

#include <iostream>

int getValueFromUserUB() // this function returns an integer value
{
 	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;

	// note: no return statement
}

int main()
{
	std::cout << getValueFromUserUB() << '\n'; // undefined behavior
	return 0;
}
