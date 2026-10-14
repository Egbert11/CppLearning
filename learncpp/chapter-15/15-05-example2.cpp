// ============================================================
// 来源小节：15.5 Class templates with member functions
// 示例说明：回顾类模板——struct Pair 的两个成员都用 T；为聚合类型
//           提供一个推导指引，使两个同类型实参能推导出 Pair<T>。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-templates-with-member-functions/
// 预期输出：
//   1 2
//   1.2 3.4
//   5 6
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

template <typename T>
struct Pair
{
	T first{};
	T second{};
};

// Here's a deduction guide for our Pair (required in C++17 or older)
// Pair objects with arguments of type T and T should deduce to Pair<T>
template <typename T>
Pair(T, T) -> Pair<T>;

int main()
{
	Pair<int> p1{ 1, 2 };
	Pair<double> p2{ 1.2, 3.4 };
	Pair p3{ 5, 6 }; // 用 CTAD 推导为 Pair<int>

	std::cout << p1.first << ' ' << p1.second << '\n';
	std::cout << p2.first << ' ' << p2.second << '\n';
	std::cout << p3.first << ' ' << p3.second << '\n';

	return 0;
}
