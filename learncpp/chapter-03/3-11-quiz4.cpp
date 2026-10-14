// 来源小节：3.x Chapter 3 summary and quiz —— 测验第 4 题（附加题，有 bug 版）
// 题目：下面是另一个有问题的"两数相加"程序。用输入 8 和 4 单步执行并修复它。
// 缺陷：readNumber() 内部把变量声明为 char x{};，输入被按字符编码存储
//       （输入 8 得到 56，输入 4 得到 52），所以相加结果错误。
// 修复：把 readNumber() 中该行的 char 改为 int。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-3-summary-and-quiz/

#include <iostream>

int readNumber()
{
	std::cout << "Please enter a number: ";
	char x{};
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
	int y { readNumber() };
	writeAnswer(x + y);

	return 0;
}
