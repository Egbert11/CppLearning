// ============================================================
// 来源小节：27.2 Basic exception handling
// 示例说明：完整的 try + 多个 catch 程序——try 中 throw -1，按顺序尝试三个
//           catch（double、int、const std::string&），最终由 int 分支处理；
//           处理完后从最后一个 catch 之后的语句继续执行。
// 原文链接：https://www.learncpp.com/cpp-tutorial/basic-exception-handling/
// 预期输出：
//   We caught an int exception with value: -1
//   Continuing on our merry way
// 备注：本示例逐字取自原文（含 main）。
// ============================================================
#include <iostream>
#include <string>

int main()
{
    try
    {
        // Statements that may throw exceptions you want to handle go here
        throw -1; // here's a trivial example
    }
    catch (double) // no variable name since we don't use the exception itself in the catch block below
    {
        // Any exceptions of type double thrown within the above try block get sent here
        std::cerr << "We caught an exception of type double\n";
    }
    catch (int x)
    {
        // Any exceptions of type int thrown within the above try block get sent here
        std::cerr << "We caught an int exception with value: " << x << '\n';
    }
    catch (const std::string&) // catch classes by const reference
    {
        // Any exceptions of type std::string thrown within the above try block get sent here
        std::cerr << "We caught an exception of type std::string\n";
    }

    // Execution continues here after the exception has been handled by any of the above catch blocks
    std::cout << "Continuing on our merry way\n";

    return 0;
}
