// ============================================================
// 来源小节：27.4 Uncaught exceptions and catch-all handlers
// 示例说明：用条件编译在 debug 版中"关闭"catch-all。NDEBUG 未定义（debug）时
//           编译进 catch(...)，能捕获异常；NDEBUG 定义（release）时改为编译进
//           catch(DummyException)——DummyException 无法实例化，因此永远捕不到
//           任何东西，从而保留调试器可用的栈信息。
// 原文链接：https://www.learncpp.com/cpp-tutorial/uncaught-exceptions-catch-all-handlers/
// 预期输出：
//   debug 构建：Abnormal termination
//   release 构建（-DNDEBUG）：异常无人处理，程序被终止。
// 备注：本示例逐字取自原文（含 main）。
// ============================================================
#include <iostream>

struct GameSession
{
    // Game session data here
};

void runGame(GameSession&)
{
    throw 1;
}

void saveGame(GameSession&)
{
    // Save user's game here
}

class DummyException // a dummy class that can't be instantiated
{
    DummyException() = delete;
};

int main()
{
    GameSession session {};

    try
    {
        runGame(session);
    }
#ifndef NDEBUG // if we're in release node
    catch(...) // compile in the catch-all handler
    {
        std::cerr << "Abnormal termination\n";
    }
#else // in debug mode, compile in a catch that will never be hit (for syntactic reasons)
    catch(DummyException)
    {
    }
#endif

    saveGame(session); // save the user's game (even if catch-all handler was hit)

    return 0;
}
