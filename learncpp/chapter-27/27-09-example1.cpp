// 来源小节：27.9 Exception specifications and noexcept
// 示例说明：noexcept 行为演示——noexcept 函数可以调用可能抛出的函数，只要异常在其内部被处理
//           而不外泄；但若异常必须穿过 noexcept 函数传给调用者，就会调用 std::terminate 并中止程序。
//           tester 本身是 noexcept，内部用 try/catch 处理异常。
// 原文链接：https://www.learncpp.com/cpp-tutorial/exception-specifications-and-noexcept/
// 预期输出（作者机器）：
//   tester (noexcept) case 1 called
//   pt (potentially throwing) called
//   Throwing exception
//   Doomed destructed
//   tester caught exception
//   Test successful
//
//   tester (noexcept) case 2 called
//   nt (noexcept) called
//   Throwing exception
//   terminate called after throwing an instance of 'int'
//   然后程序被 abort（非零退出码）；本机栈未展开，故第二个 Doomed 未被析构。
// 注意：程序是"故意"以终止演示 noexcept 违约的，运行时以非零码结束属于预期行为。

// h/t to reader yellowEmu for the first draft of this program
#include <iostream>

class Doomed
{
public:
    ~Doomed()
    {
        std::cout << "Doomed destructed\n";
    }
};

void thrower()
{
    std::cout << "Throwing exception\n";
    throw 1;
}

void pt()
{
    std::cout << "pt (potentally throwing) called\n";
    //This object will be destroyed during stack unwinding (if it occurs)
    Doomed doomed{};
    thrower();
    std::cout << "This never prints\n";
}

void nt() noexcept
{
    std::cout << "nt (noexcept) called\n";
    //This object will be destroyed during stack unwinding (if it occurs)
    Doomed doomed{};
    thrower();
    std::cout << "this never prints\n";
}

void tester(int c) noexcept
{
    std::cout << "tester (noexcept) case " << c << " called\n";
    try
    {
        (c == 1) ? pt() : nt();
    }
    catch (...)
    {
        std::cout << "tester caught exception\n";
    }
}

int main()
{
    std::cout << std::unitbuf; // flush buffer after each insertion
    std::cout << std::boolalpha; // print boolean as true/false
    tester(1);
    std::cout << "Test successful\n\n";
    tester(2);
    std::cout << "Test successful\n";

    return 0;
}
