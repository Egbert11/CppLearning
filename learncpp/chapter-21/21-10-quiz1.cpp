// 来源小节：21.10 Overloading the parenthesis operator（测验 1 解答）
// 示例说明：MyString 包装 std::string，重载 operator<< 打印自身，重载 operator()
//           返回从 start 起、长度为 length 的子串（用 std::string::substr，返回 MyString）。
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

	MyString operator()(int start, int length)
	{
		assert(start >= 0);
		assert(start + length <= static_cast<int>(m_string.length()) && "MyString::operator(int, int): Substring is out of range");

		return MyString{ m_string.substr(
			static_cast<std::string::size_type>(start),
			static_cast<std::string::size_type>(length)) };
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
