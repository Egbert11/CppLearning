// 来源小节：3.x Chapter 3 summary and quiz —— 测验第 2 题（有 bug 版）
// 题目：下面这个"两数相除"的程序行为不正确。请单步执行，输入 8 和 4，然后修复它。
// 缺陷：第二次读入误写成 x = readNumber();（应为 y = readNumber();），导致 y 仍为 0，
//       x/y 触发除零 → 未定义行为。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-3-summary-and-quiz/
//
// 提示：单步到 writeAnswer(x/y); 处，在监视窗口/悬停中查看 x 与 y 的值。

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
	int x{ };
	int y{ };

	x = readNumber();
	x = readNumber();           // 缺陷：第二次又赋给了 x，y 保持为 0
	writeAnswer(x/y);

	return 0;
}
