// 来源小节：27.6 Rethrowing exceptions
// 示例说明：在 catch 块中抛出"全新"的异常（此处为 char 'q'），把错误向上传给调用者。
//           演示：catch 块里抛出的异常不会被它所在的 catch 捕获，而是沿栈向上传播。
// 原文链接：https://www.learncpp.com/cpp-tutorial/rethrowing-exceptions/
// 说明：Database 与 g_log 的模拟实现仅用于让片段可编译。

#include <iostream>
#include <string>
#include <cassert>

// --- 为令原文片段可编译而补充的模拟实现（原文未提供） ---
struct Database
{
    int getIntValue(const std::string& /*table*/, const std::string& /*key*/)
    {
        throw 1; // throws int exception on failure
    }
};

struct Log
{
    void logError(const std::string& message) { std::cerr << message << '\n'; }
};

Log g_log;
// --- 模拟实现结束 ---

// --- 原文示例片段 ---
int getIntValueFromDatabase(Database* d, std::string table, std::string key)
{
    assert(d);

    try
    {
        return d->getIntValue(table, key); // throws int exception on failure
    }
    catch (int exception)
    {
        // Write an error to some global logfile
        g_log.logError("getIntValueFromDatabase failed");

        // Throw char exception 'q' up the stack to be handled by caller
        throw 'q';
    }
}
// --- 原文示例片段结束 ---

int main()
{
    Database d;
    try
    {
        int value{ getIntValueFromDatabase(&d, "table", "key") };
        std::cout << "value: " << value << '\n';
    }
    catch (char c)
    {
        std::cout << "Caught char exception: " << c << '\n';
    }

    return 0;
}
