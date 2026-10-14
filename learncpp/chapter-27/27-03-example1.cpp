// ============================================================
// 来源小节：27.3 Exceptions, functions, and stack unwinding
// 示例说明：模块化的 mySqrt() 在出错时抛出异常，自己不处理，把处理责任交给
//           调用者（调用者把对它的调用放在 try 块里）。说明 try 块不仅能捕获
//           块内语句抛出的异常，也能捕获"在 try 块内被调用函数"抛出的异常。
// 原文链接：https://www.learncpp.com/cpp-tutorial/exceptions-functions-and-stack-unwinding/
// 预期输出（示例）：
//   输入 -4 -> Enter a number: -4
//              Error: Can not take sqrt of negative number
// 备注：本示例逐字取自原文（含 main），需要从标准输入读取数字。
// ============================================================
#include <cmath> // for sqrt() function
#include <iostream>

// A modular square root function
double mySqrt(double x)
{
    // If the user entered a negative number, this is an error condition
    if (x < 0.0)
        throw "Can not take sqrt of negative number"; // throw exception of type const char*

    return std::sqrt(x);
}

int main()
{
    std::cout << "Enter a number: ";
    double x {};
    std::cin >> x;

    try // Look for exceptions that occur within try block and route to attached catch block(s)
    {
        double d = mySqrt(x);
        std::cout << "The sqrt of " << x << " is " << d << '\n';
    }
    catch (const char* exception) // catch exceptions of type const char*
    {
        std::cerr << "Error: " << exception << std::endl;
    }

    return 0;
}
