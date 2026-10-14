// ============================================================
// 来源小节：15.5 Class templates with member functions
// 示例说明：类模板的成员函数在类外定义——必须重新给出 template <typename T>，
//           并用完全模板化的类名 Pair<T>::（不能写成 Pair::）。
//           非聚合类有构造函数，因此 CTAD 可直接工作，无需推导指引。
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

	bool isEqual(const Pair<T>& pair);
};

// 类外定义成员函数模板：重写 template，并用 Pair<T>:: 限定
template <typename T>
bool Pair<T>::isEqual(const Pair<T>& pair)
{
	return m_first == pair.m_first && m_second == pair.m_second;
}

int main()
{
	Pair p1{ 5, 6 }; // 用 CTAD 推导为 Pair<int>
	std::cout << std::boolalpha;
	std::cout << p1.isEqual(Pair{ 5, 6 }) << '\n'; // true
	std::cout << p1.isEqual(Pair{ 1, 2 }) << '\n'; // false

	return 0;
}
