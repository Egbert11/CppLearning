// ============================================================
// 来源小节：27.2 Basic exception handling
// 示例说明：异常会被"立即"处理——try 块中抛出 double 异常后，紧随其后的
//           std::cout << "This never prints\n"; 永远不会执行，控制权直接跳到
//           匹配的 catch 块。
// 原文链接：https://www.learncpp.com/cpp-tutorial/basic-exception-handling/
// 预期输出：We caught a double of value: 4.5
// 备注：本示例逐字取自原文（含 main）。
// ============================================================
#include <iostream>

int main()
{
    try
    {
        throw 4.5; // throw exception of type double
        std::cout << "This never prints\n";
    }
    catch (double x) // handle exception of type double
    {
        std::cerr << "We caught a double of value: " << x << '\n';
    }

    return 0;
}
