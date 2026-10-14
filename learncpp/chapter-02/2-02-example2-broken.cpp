// 来源小节：2.2 Function return values (value-returning functions)
// 示例说明：失败的改写 —— getValueFromUser() 是 void，虽然读了输入却不返回给调用者，
//           于是 main() 里的 num 仍是 0（用户输入的值被丢失了）。
//           本程序能编译，但逻辑是错的（原文标注 "This program doesn't work"）。
//           预期输出（无论输入什么）：0 doubled is: 0
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-return-values-value-returning-functions/
//
// 编译：g++ -std=c++20 -Wall 2-02-example2-broken.cpp -o a

#include <iostream>

void getValueFromUser() // this function now returns void
{
 	std::cout << "Enter an integer: ";
 	int input{};
 	std::cin >> input;
}

int main() // This program doesn't work
{
    getValueFromUser(); // Ask user for input

	int num{}; // how do we get the value from getValueFromUser() into num?

	std::cout << num << " doubled is: " << num * 2 << '\n';

	return 0;
}
