// 来源小节：3.x Chapter 3 summary and quiz —— 测验第 1 题（有 bug 版）
// 题目：下面这个"两数相加"的程序行为不正确。请用集成调试器单步执行、同时监视 x，找出并修复问题。
// 缺陷：main 中的 readNumber(x); 丢弃了返回值；且 readNumber 不应接收参数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-3-summary-and-quiz/
//
// 提示：在调试器中单步并监视 x，观察第一次 readNumber 的结果去了哪里。

#include <iostream>

int readNumber(int x)
{
	std::cout << "Please enter a number: ";
	std::cin >> x;
	return x;
}

void writeAnswer(int x)
{
	std::cout << "The sum is: " << x << '\n';
}

int main()
{
	int x {};
	readNumber(x);              // 缺陷：返回值被丢弃
	x = x + readNumber(x);

	writeAnswer(x);

	return 0;
}
