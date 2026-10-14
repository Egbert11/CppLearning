// ============================================================
// 来源小节：27.5 Exceptions, classes, and inheritance
// 示例说明：自定义异常类 ArrayException 配合重载的 operator[]。下标越界时抛出
//           ArrayException 对象，main 以 const ArrayException& 捕获（按 const
//           引用捕获可避免拷贝与对象切片）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/exceptions-classes-and-inheritance/
// 预期输出：An array exception occurred (Invalid index)
// 备注：本示例逐字取自原文（含 main）。用 -Wall 编译会提示 main 中 value
//       未使用（unused variable 'value'），此为原文即有的写法，保留原样。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

class ArrayException
{
private:
	std::string m_error;

public:
	ArrayException(std::string_view error)
		: m_error{ error }
	{
	}

	const std::string& getError() const { return m_error; }
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
			throw ArrayException{ "Invalid index" };

		return m_data[index];
	}

};

int main()
{
	IntArray array;

	try
	{
		int value{ array[5] }; // out of range subscript
	}
	catch (const ArrayException& exception)
	{
		std::cerr << "An array exception occurred (" << exception.getError() << ")\n";
	}
}
