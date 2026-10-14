// ============================================================
// 来源小节：15.5 Class templates with member functions
// 示例说明：回顾函数模板——模板参数声明 template <typename T> 让 T
//           既可作为函数参数类型，也可作为返回类型使用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-templates-with-member-functions/
// 预期输出：2 与 3.5
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

template <typename T>
T max(T x, T y)
{
	return (x < y) ? y : x;
}

int main()
{
	std::cout << max(1, 2) << '\n';       // 实例化 max<int>
	std::cout << max(3.5, 2.3) << '\n';   // 实例化 max<double>

	return 0;
}
