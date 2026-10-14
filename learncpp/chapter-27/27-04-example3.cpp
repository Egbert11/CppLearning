// ============================================================
// 来源小节：27.4 Uncaught exceptions and catch-all handlers
// 示例说明：用 catch-all 包裹 main 的正文——runGame() 抛出异常时由 catch(...)
//           捕获并打印 "Abnormal termination"，随后仍执行 saveGame() 以保存
//           玩家进度，再正常退出。这样能有序地展开栈、在退出前做清理。
// 原文链接：https://www.learncpp.com/cpp-tutorial/uncaught-exceptions-catch-all-handlers/
// 预期输出：Abnormal termination
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

int main()
{
    GameSession session{};

    try
    {
        runGame(session);
    }
    catch(...)
    {
        std::cerr << "Abnormal termination\n";
    }

    saveGame(session); // save the user's game (even if catch-all handler was hit)

    return 0;
}
