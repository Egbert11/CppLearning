// ============================================================
// 来源小节：12.x Chapter 12 summary and quiz（本章总结小节）
// 示例说明：测验第 2 题。问该程序输出什么。答案是 `7 6`——因为引用不能被
//           重新绑定（reseated），`ref = y` 等价于 `x = y`，而不是让 ref
//           改去指代 y。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-12-summary-and-quiz/
// 预期输出：7 6
// 备注：本节代码为按原文清单忠实重建（测验 2 解答）。
// ============================================================
#include <iostream>

int main()
{
	int x{ 4 };
	int y{ 6 };

	int& ref{ x }; // ref is now an alias for `x`
	++ref;   // x is now 5
	ref = y; // x is now 6 (this does NOT make ref an alias for y)
	++ref;   // x is now 7

	std::cout << x << ' ' << y; // prints 7 6

	return 0;
}
