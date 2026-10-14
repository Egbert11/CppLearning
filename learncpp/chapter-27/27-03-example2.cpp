// ============================================================
// 来源小节：27.3 Exceptions, functions, and stack unwinding
// 示例说明：完整的栈展开（stack unwinding）演示。D() 抛出 int 异常后沿调用栈
//           向上传播：C() 未处理 -> B() 的两个 try 都未能匹配（类型不符 / 异常
//           不在该 try 内抛出）-> A() 的 catch(int) 捕获并处理。异常被处理时，
//           被展开函数栈帧中的局部变量会被销毁。
// 原文链接：https://www.learncpp.com/cpp-tutorial/exceptions-functions-and-stack-unwinding/
// 预期输出：
//   Start main
//   Start A
//   Start B
//   Start C
//   Start D
//   D throwing int exception
//   A caught int exception
//   End A
//   End main
// 备注：本示例逐字取自原文（含 main）。
// ============================================================
#include <iostream>

void D() // called by C()
{
    std::cout << "Start D\n";
    std::cout << "D throwing int exception\n";

    throw - 1;

    std::cout << "End D\n"; // skipped over
}

void C() // called by B()
{
    std::cout << "Start C\n";
    D();
    std::cout << "End C\n";
}

void B() // called by A()
{
    std::cout << "Start B\n";

    try
    {
        C();
    }
    catch (double) // not caught: exception type mismatch
    {
        std::cerr << "B caught double exception\n";
    }

    try
    {
    }
    catch (int) // not caught: exception not thrown within try
    {
        std::cerr << "B caught int exception\n";
    }

    std::cout << "End B\n";
}

void A() // called by main()
{
    std::cout << "Start A\n";

    try
    {
        B();
    }
    catch (int) // exception caught here and handled
    {
        std::cerr << "A caught int exception\n";
    }
    catch (double) // not called because exception was handled by prior catch block
    {
        std::cerr << "A caught double exception\n";
    }

    // execution continues here after the exception is handled
    std::cout << "End A\n";
}

int main()
{
    std::cout << "Start main\n";

    try
    {
        A();
    }
    catch (int) // not called because exception was handled by A
    {
        std::cerr << "main caught int exception\n";
    }
    std::cout << "End main\n";

    return 0;
}
