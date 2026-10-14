// 来源小节：3.10 Finding issues before they become problems
// 示例说明：用一个测试函数 testadd() 来"exercise"（检验）add()，这是"原始形式的单元测试"。
//           把这种测试函数保留下来，每次修改 add() 后重跑，就能确认没有把原本正常的逻辑改坏。
// 原文链接：https://www.learncpp.com/cpp-tutorial/finding-issues-before-they-become-problems/
//
// 预期输出：
//   This function should print: 2 0 0 -2
//   2 0 0 -2

#include <iostream>

int add(int x, int y)
{
	return x + y;
}

void testadd()
{
	std::cout << "This function should print: 2 0 0 -2\n";
	std::cout << add(1, 1) << ' ';
	std::cout << add(-1, 1) << ' ';
	std::cout << add(1, -1) << ' ';
	std::cout << add(-1, -1) << ' ';
}

int main()
{
	testadd();

	return 0;
}
