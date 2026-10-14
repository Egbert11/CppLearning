// 来源小节：3.x Chapter 3 summary and quiz —— 测验第 2 题（修正版）
// 题目：修复第 2 题中"两数相除"程序的缺陷（除零）。
// 修正：把两次读入分别赋给 x 和 y，再计算 x/y。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-3-summary-and-quiz/
//
// 预期输出（例如输入 8 和 4）：
//   Please enter a number: 8
//   Please enter a number: 4
//   The quotient is: 2
// 备注：整数除法会丢弃小数部分（见第 6.2 课）。

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
	std::cout << "The quotient is: " << x << '\n';
}

int main()
{
	int x{ readNumber() };
	int y{ readNumber() };
	writeAnswer(x/y);

	return 0;
}
