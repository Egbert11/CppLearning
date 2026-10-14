// ============================================================
// 来源小节：26.x Chapter 26 summary and quiz（测验第 2 题解答）
// 题目：写一个 Pair 类，允许分别为一对中的两个值指定不同类型。
//       （因 C++ 目前不允许“重载”仅模板参数个数或类型不同的类，故改名 Pair。）
// 示例说明：两个类型参数 T、S 的 Pair，成员分别是 T 与 S。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-26-summary-and-quiz/
// 预期输出：
//   Pair: 5 6.7
//   Pair: 2.3 4
// 备注：代码取自原文 HTML 逐字抽取。
// ============================================================
#include <iostream>

template <typename T, typename S>
class Pair
{
private:
	T m_x;
	S m_y;

public:
	Pair(const T& x, const S& y)
		: m_x{x}, m_y{y}
	{
	}

	T& first() { return m_x; }
	S& second() { return m_y; }
	const T& first() const { return m_x; }
	const S& second() const { return m_y; }
};

int main()
{
	Pair<int, double> p1 { 5, 6.7 };
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair<double, int> p2 { 2.3, 4 };
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	return 0;
}
