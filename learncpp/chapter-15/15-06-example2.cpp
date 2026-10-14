// ============================================================
// 来源小节：15.6 Static member variables
// 示例说明：普通成员变量"每个对象各有一份"。修改 first.value 不影响
//           second.value，两者是相互独立的副本。
// 原文链接：https://www.learncpp.com/cpp-tutorial/static-member-variables/
// 预期输出：2 然后 1
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

struct Something
{
	int value{ 1 };
};

int main()
{
	Something first{};
	Something second{};

	first.value = 2;

	std::cout << first.value << '\n';  // 2
	std::cout << second.value << '\n'; // 1

	return 0;
}
