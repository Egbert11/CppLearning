// ============================================================
// 来源小节：27.5 Exceptions, classes, and inheritance
// 示例说明：自定义异常类派生自 std::exception，自己保存错误串并重写 what()。
//           what() 是 noexcept 的，重写时必须保持同样的说明符；派生类处理器
//           放在 std::exception 处理器之前。
// 原文链接：https://www.learncpp.com/cpp-tutorial/exceptions-classes-and-inheritance/
// 预期输出：An array exception occurred (Invalid index)
// 备注：本示例逐字取自原文（含 main）。用 -Wall 编译会提示 main 中 value
//       未使用（unused variable 'value'），此为原文即有的写法，保留原样。
// ============================================================
#include <exception> // for std::exception
#include <iostream>
#include <string>
#include <string_view>

class ArrayException : public std::exception
{
private:
	std::string m_error{}; // handle our own string

public:
	ArrayException(std::string_view error)
		: m_error{error}
	{
	}

	// std::exception::what() returns a const char*, so we must as well
	const char* what() const noexcept override { return m_error.c_str(); }
};

class IntArray
{
private:
	int m_data[3] {}; // assume array is length 3 for simplicity

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
