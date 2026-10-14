// ============================================================
// 来源小节：27.2 Basic exception handling
// 示例说明：更贴近实际的例子——计算平方根。输入负数时抛出一个 const char*
//           异常并打印错误；输入合法数字则打印结果（此时 catch 不会执行）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/basic-exception-handling/
// 预期输出（示例）：
//   输入 9  -> Enter a number: 9
//              The sqrt of 9 is 3
//   输入 -4 -> Enter a number: -4
//              Error: Can not take sqrt of negative number
// 备注：本示例逐字取自原文（含 main），需要从标准输入读取数字。
// ============================================================
#include <cmath> // for sqrt() function
#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    double x {};
    std::cin >> x;

    try // Look for exceptions that occur within try block and route to attached catch block(s)
    {
        // If the user entered a negative number, this is an error condition
        if (x < 0.0)
            throw "Can not take sqrt of negative number"; // throw exception of type const char*

        // Otherwise, print the answer
        std::cout << "The sqrt of " << x << " is " << std::sqrt(x) << '\n';
    }
    catch (const char* exception) // catch exceptions of type const char*
    {
        std::cerr << "Error: " << exception << '\n';
    }
}
