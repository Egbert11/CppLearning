// 来源小节：27.6 Rethrowing exceptions
// 示例说明：getIntValueFromDatabase() 捕获 int 异常后只写了日志，既没有真正处理错误，
//           也没有向调用者反馈失败——演示"返回值无法表示失败"时的困境。
// 原文链接：https://www.learncpp.com/cpp-tutorial/rethrowing-exceptions/
// 预期警告：函数返回类型为 int，但存在一条不返回值的控制流路径，g++ -Wall 会产生
//           -Wreturn-type 警告。原文刻意保持这一形态来说明问题所在，请勿"修复"。
// 预期行为：函数走到末尾而没有 return，属于未定义行为；本机 g++ 会在此处生成 ud2 指令，
//           运行到该路径时以 SIGILL（Illegal instruction）终止——这正是"错误没有被真正处理"的后果。
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

        // However, we haven't actually handled this error
        // So what do we do here?
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
    catch (int)
    {
        std::cout << "(caller never sees this int; the function swallowed it)\n";
    }

    return 0;
}
