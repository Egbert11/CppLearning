// ============================================================
// 来源小节：26.x Chapter 26 summary and quiz（测验第 3 题解答）
// 题目：string-value pair 的第一值恒为字符串类型、第二值可为任意类型。写一个
//       模板类 StringValuePair，继承自一个（以 std::string 为第一类型的）
//       部分特化 Pair 类，并允许用户指定第二类型。
// 示例说明：StringValuePair<S> 继承 Pair<std::string, S>；构造函数收
//           std::string_view（它不会隐式转成 std::string，故显式 static_cast）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-26-summary-and-quiz/
// 预期输出：
//   Pair: Hello 5
// 备注：代码取自原文 HTML 逐字抽取。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

template <typename T, typename S>
class Pair
{
private:
	T m_x{};
	S m_y{};

public:
	Pair(const T& x, const S& y)
		: m_x{ x }, m_y{ y }
	{
	}

	T& first() { return m_x; }
	S& second() { return m_y; }
	const T& first() const { return m_x; }
	const S& second() const { return m_y; }
};

template <typename S>
class StringValuePair : public Pair<std::string, S>
{
public:
	StringValuePair(std::string_view key, const S& value)
                // a std::string_view won't implicitly convert to a std::string, we must be explicit
		: Pair<std::string, S>{ static_cast<std::string>(key), value }
	{
	}
};

int main()
{
	StringValuePair<int> svp{ "Hello", 5 };
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}
