// 来源小节：27.6 Rethrowing exceptions
// 示例说明：重抛异常的"错误方式"之一——用 `throw exception;` 抛出 catch 形参的副本，
//           而不是原来那个异常对象。此版本形参是 int，看不出切片，但会多一次拷贝。
//           （原文随后用 Base& / Derived 的例子说明了真正的危害：对象切片。）
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

        throw exception; // 抛出的是形参副本（copy-initialized），并非原始异常对象
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
    catch (int exception)
    {
        std::cout << "Caught int exception: " << exception << '\n';
    }

    return 0;
}
