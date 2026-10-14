// ============================================================
// 来源小节：15.5 Class templates with member functions
// 文件说明：Quiz #1 解答——Triad 类模板，三个相互独立的类型参数
//           T, U, V；构造函数、const 访问函数，以及声明在类内、
//           定义在类外的 print()。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-templates-with-member-functions/
// 预期输出：
//   [1, 2, 3]
//   1
//   [1, 2.3, Hello]
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <string>

template <typename T, typename U, typename V>
class Triad
{
private:
	T m_first{};
	U m_second{};
	V m_third{};

public:
	Triad(const T& first, const U& second, const V& third)
		: m_first{ first }
		, m_second{ second }
		, m_third{ third }
	{
	}

	const T& first() const { return m_first; }
	const U& second() const { return m_second; }
	const V& third() const { return m_third; }

	void print() const;
};

template <typename T, typename U, typename V>
void Triad<T, U, V>::print() const
{
	std::cout << '[' << m_first << ", " << m_second << ", " << m_third << ']';
}

int main()
{
	Triad<int, int, int> t1{ 1, 2, 3 };
	t1.print();
	std::cout << '\n';
	std::cout << t1.first() << '\n';

	using namespace std::literals::string_literals;
	const Triad t2{ 1, 2.3, "Hello"s }; // CTAD 推导为 Triad<int, double, std::string>
	t2.print();
	std::cout << '\n';

	return 0;
}
