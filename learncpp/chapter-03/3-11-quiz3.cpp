// 来源小节：3.x Chapter 3 summary and quiz —— 测验第 3 题（调用栈）
// 题目：当执行点位于 d() 中被标注 // here 的那一行时，调用栈中包含哪些函数？（只需函数名）
// 答案：自栈顶到底部依次为 d、b、a、main。
// 说明：main 调用 a(); a 调用 b(); b 依次调用 c(); d(); 在 d() 内部观察调用栈即可验证。
// 在调试器中单步运行观察：在 // here 处暂停并打开"调用栈"窗口。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-3-summary-and-quiz/

#include <iostream>

void d()
{ // here
}

void c()
{
}

void b()
{
	c();
	d();
}

void a()
{
	b();
}

int main()
{
	a();

	return 0;
}
