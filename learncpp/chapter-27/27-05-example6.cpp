// ============================================================
// 来源小节：27.5 Exceptions, classes, and inheritance
// 示例说明：抛出标准异常 std::runtime_error（定义于 <stdexcept>），它接受
//           一条自定义消息，由 catch (const std::exception&) 统一捕获。
// 原文链接：https://www.learncpp.com/cpp-tutorial/exceptions-classes-and-inheritance/
// 预期输出：Standard exception: Bad things happened
// 备注：本示例逐字取自原文（含 main）。
// ============================================================
#include <exception> // for std::exception
#include <iostream>
#include <stdexcept> // for std::runtime_error

int main()
{
	try
	{
		throw std::runtime_error("Bad things happened");
	}
	// This handler will catch std::exception and all the derived exceptions too
	catch (const std::exception& exception)
	{
		std::cerr << "Standard exception: " << exception.what() << '\n';
	}

	return 0;
}
