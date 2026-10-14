// ============================================================
// 来源小节：26.x Chapter 26 summary and quiz（测验第 1 题解答）
// 题目：有时我们需要“成对出现”的数据。写一个模板类 Pair1，只允许用户定义一个
//       模板类型，该类型同时用于一对中的两个值。
// 示例说明：单类型参数的 Pair1，两个成员都是 T，提供非 const/const 两套访问器。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-26-summary-and-quiz/
// 预期输出：
//   Pair: 5 8
//   Pair: 2.3 4.5
// 备注：代码取自原文 HTML 逐字抽取。
// ============================================================
#include <iostream>

template <typename T>
class Pair1
{
private:
	T m_x {};
	T m_y {};

public:
	Pair1(const T& x, const T& y)
		: m_x{ x }, m_y{ y }
	{
	}

	T& first() { return m_x; }
	T& second() { return m_y; }
	const T& first() const { return m_x; }
	const T& second() const { return m_y; }
};

int main()
{
	Pair1<int> p1 { 5, 8 };
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair1<double> p2 { 2.3, 4.5 };
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	return 0;
}
