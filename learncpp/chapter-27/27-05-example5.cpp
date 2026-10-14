// ============================================================
// 来源小节：27.5 Exceptions, classes, and inheritance
// 示例说明：标准库异常都以 std::exception 为基类，因此一个
//           catch (const std::exception&) 就能捕获全部标准异常（及其派生类）。
//           这里故意让 std::string::resize() 触发一个标准异常来演示。
// 原文链接：https://www.learncpp.com/cpp-tutorial/exceptions-classes-and-inheritance/
// 预期输出（作者环境 MSVC）：Standard exception: string too long
//   注：what() 返回的文本依实现而定；libstdc++（MinGW）下文本可能不同，
//   属正常现象——切勿依赖 what() 的具体内容。
// 备注：本示例逐字取自原文（含 main）。
// ============================================================
#include <cstddef> // for std::size_t
#include <exception> // for std::exception
#include <iostream>
#include <limits>
#include <string> // for this example

int main()
{
    try
    {
        // Your code using standard library goes here
        // We'll trigger one of these exceptions intentionally for the sake of the example
        std::string s;
        s.resize(std::numeric_limits<std::size_t>::max()); // will trigger a std::length_error or allocation exception
    }
    // This handler will catch std::exception and all the derived exceptions too
    catch (const std::exception& exception)
    {
        std::cerr << "Standard exception: " << exception.what() << '\n';
    }

    return 0;
}
