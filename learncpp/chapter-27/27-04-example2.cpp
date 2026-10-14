// ============================================================
// 来源小节：27.4 Uncaught exceptions and catch-all handlers
// 示例说明：catch-all 处理器——catch(...) 使用省略号，可以捕获任意类型的异常。
//           main 中 throw 5（int），先尝试 catch(double) 不匹配，最终由
//           catch(...) 捕获。注意 catch-all 必须放在最后。
// 原文链接：https://www.learncpp.com/cpp-tutorial/uncaught-exceptions-catch-all-handlers/
// 预期输出：We caught an exception of an undetermined type
// 备注：本示例逐字取自原文（含 main）。
// ============================================================
#include <iostream>

int main()
{
	try
	{
		throw 5; // throw an int exception
	}
	catch (double x)
	{
		std::cout << "We caught an exception of type double: " << x << '\n';
	}
	catch (...) // catch-all handler
	{
		std::cout << "We caught an exception of an undetermined type\n";
	}
}
