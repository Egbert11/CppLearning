// ============================================================
// 来源小节：27.5 Exceptions, classes, and inheritance
// 示例说明：让自定义异常类改为派生自 std::runtime_error——它已经帮你处理了
//           错误串与 what()，所以我们无需再自己保存字符串或重写 what()，
//           构造时把消息转发给它即可。
// 原文链接：https://www.learncpp.com/cpp-tutorial/exceptions-classes-and-inheritance/
// 预期输出：An array exception occurred (Invalid index)
// 备注：本示例逐字取自原文（含 main）。用 -Wall 编译会提示 main 中 value
//       未使用（unused variable 'value'），此为原文即有的写法，保留原样。
// ============================================================
#include <exception> // for std::exception
#include <iostream>
#include <stdexcept> // for std::runtime_error
#include <string>

class ArrayException : public std::runtime_error
{
public:
	// std::runtime_error takes either a null-terminated const char* or a const std::string&.
	// We will follow their lead and take a const std::string&
	ArrayException(const std::string& error)
		: std::runtime_error{ error } // std::runtime_error will handle the string
	{
	}


        // no need to override what() since we can just use std::runtime_error::what()
};

class IntArray
{
private:
	int m_data[3]{}; // assume array is length 3 for simplicity

public:
	IntArray() {}

	int getLength() const { return 3; }

	int& operator[](const int index)
	{
		if (index < 0 || index >= getLength())
			throw ArrayException("Invalid index");

		return m_data[index];
	}

};

int main()
{
	IntArray array;

	try
	{
		int value{ array[5] };
	}
	catch (const ArrayException& exception) // derived catch blocks go first
	{
		std::cerr << "An array exception occurred (" << exception.what() << ")\n";
	}
	catch (const std::exception& exception)
	{
		std::cerr << "Some other std::exception occurred (" << exception.what() << ")\n";
	}
}
