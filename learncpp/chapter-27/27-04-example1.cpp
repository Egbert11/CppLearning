// ============================================================
// 来源小节：27.4 Uncaught exceptions and catch-all handlers
// 示例说明：mySqrt() 会为负数抛出异常，但 main 里完全没有 try/catch——异常
//           一路传播，无人处理，最终调用 std::terminate() 终止程序（可能不会
//           展开栈）。输入合法正数则可正常结束。
// 原文链接：https://www.learncpp.com/cpp-tutorial/uncaught-exceptions-catch-all-handlers/
// 预期输出（示例，输入 9）：
//   Enter a number: 9
//   The sqrt of 9 is 3
//   若输入负数（如 -4），程序因未捕获异常而被终止（行为/退出码依实现而定）。
// 备注：本示例逐字取自原文（含 main）。
// ============================================================
#include <iostream>
#include <cmath> // for sqrt() function

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
    double x;
    std::cin >> x;

    // Look ma, no exception handler!
    std::cout << "The sqrt of " << x << " is " << mySqrt(x) << '\n';

    return 0;
}
