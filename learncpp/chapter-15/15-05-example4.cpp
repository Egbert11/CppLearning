// ============================================================
// 来源小节：15.5 Class templates with member functions
// 示例说明：注入类名（injected class name）。在类作用域内，非限定的类名
//           Pair 就是完全模板化名字 Pair<T> 的简写，所以参数可以写成
//           const Pair&。注意这里 Pair 只是简写，不是 CTAD（CTAD 不作用于
//           函数参数）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-templates-with-member-functions/
// 预期输出：先 true，后 false
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

template <typename T>
class Pair
{
private:
	T m_first{};
	T m_second{};

public:
	Pair(const T& first, const T& second)
		: m_first{ first }
		, m_second{ second }
	{
	}

	// 参数类型写作 Pair（注入类名），它就是 Pair<T> 的简写
	bool isEqual(const Pair& pair);
};

template <typename T>
bool Pair<T>::isEqual(const Pair& pair)
{
	return m_first == pair.m_first && m_second == pair.m_second;
}

int main()
{
	Pair p1{ 5, 6 };
	std::cout << std::boolalpha;
	std::cout << p1.isEqual(Pair{ 5, 6 }) << '\n'; // true
	std::cout << p1.isEqual(Pair{ 1, 2 }) << '\n'; // false

	return 0;
}
