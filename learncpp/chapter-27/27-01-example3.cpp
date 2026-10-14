// ============================================================
// 来源小节：27.1 The need for exceptions
// 示例说明：用"输出参数 + 成功标志"返回错误——本函数需要额外传一个 bool&，
//           调用方在使用结果前必须先检查它。此例展示返回码方案的第二、第三个
//           缺点：一个返回值不够用、且每次调用后都要检查。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-need-for-exceptions/
// 预期输出：The answer is 1.66667
// 备注：本示例逐字取自原文（含 main）。
// ============================================================
#include <iostream>

double divide(int x, int y, bool& outSuccess)
{
    if (y == 0)
    {
        outSuccess = false;
        return 0.0;
    }

    outSuccess = true;
    return static_cast<double>(x)/y;
}

int main()
{
    bool success {}; // we must now pass in a bool value to see if the call was successful
    double result { divide(5, 3, success) };

    if (!success) // and check it before we use the result
        std::cerr << "An error occurred" << std::endl;
    else
        std::cout << "The answer is " << result << '\n';
}
