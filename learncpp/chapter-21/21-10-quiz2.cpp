// 来源小节：21.10 Overloading the parenthesis operator（测验 2 额外加分解答）
// 示例说明：把上一个测验的 operator() 改为返回 std::string_view，避免三次 std::string 拷贝：
//           直接对 m_string 构造 string_view 再 substr，返回的是对原字符串的“视图”。
//           注意不要返回指向临时对象的视图，否则会悬垂（dangling）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-parenthesis-operator/
// 说明：本节代码为按原文描述重建。
// 预期输出：world

#include <cassert>
#include <iostream>
#include <string>
#include <string_view>

class MyString
{
private:
	std::string m_string{};

public:
	MyString(std::string_view string = {})
		: m_string{ string }
	{
	}

	std::string_view operator()(int start, int length)
	{
		assert(start >= 0);
		assert(start + length <= static_cast<int>(m_string.length()) && "MyString::operator(int, int): Substring is out of range");

		// Create a std::string_view of m_string, so we can use std::string_view::substr() instead of std::string::substr()
		return std::string_view{ m_string }.substr(
			static_cast<std::string_view::size_type>(start),
			static_cast<std::string_view::size_type>(length));
	}

	friend std::ostream& operator<<(std::ostream& out, const MyString& s)
	{
		out << s.m_string;
		return out;
	}
};

int main()
{
	MyString s{ "Hello, world!" };
	std::cout << s(7, 5) << '\n'; // start at index 7 and return 5 characters

	return 0;
}
