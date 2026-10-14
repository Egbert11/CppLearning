// 来源小节：3.x Chapter 3 summary and quiz —— 测验第 1 题（修正版）
// 题目：修复第 1 题中"两数相加"程序的缺陷。
// 修正：readNumber 改为无参并用局部变量 x；main 用 int x { readNumber() }; 并累加第二次读入。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-3-summary-and-quiz/
//
// 预期输出（例如输入 4 和 6）：
//   Please enter a number: 4
//   Please enter a number: 6
//   The sum is: 10

#include <iostream>

int readNumber()
{
	std::cout << "Please enter a number: ";
	int x {};
	std::cin >> x;
	return x;
}

void writeAnswer(int x)
{
	std::cout << "The sum is: " << x << '\n';
}

int main()
{
	int x { readNumber() };
	x = x + readNumber();

	writeAnswer(x);

	return 0;
}
