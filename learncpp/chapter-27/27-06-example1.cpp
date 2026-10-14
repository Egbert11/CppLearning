// 来源小节：27.6 Rethrowing exceptions
// 示例说明：返回码风格的错误处理——createDatabase() 在失败时记录日志并返回 nullptr。
//           演示"可以用返回值表示失败"时无需重新抛出异常的场景。
// 原文链接：https://www.learncpp.com/cpp-tutorial/rethrowing-exceptions/
// 说明：Database 与 g_log 的模拟实现是为了让原文片段可独立编译而补充的（原文未给出其定义），
//       被演示的调用逻辑本身照原文保留。

#include <iostream>
#include <string>

// --- 为令原文片段可编译而补充的模拟实现（原文未提供） ---
struct Database
{
    void open(const std::string& /*filename*/)
    {
        throw 1; // assume this throws an int exception on failure
    }
};

struct Log
{
    void logError(const std::string& message) { std::cerr << message << '\n'; }
};

Log g_log;
// --- 模拟实现结束 ---

// --- 原文示例片段 ---
Database* createDatabase(std::string filename)
{
    Database* d {};

    try
    {
        d = new Database{};
        d->open(filename); // assume this throws an int exception on failure
        return d;
    }
    catch (int exception)
    {
        // Database creation failed
        delete d;
        // Write an error to some global logfile
        g_log.logError("Creation of Database failed");
    }

    return nullptr;
}
// --- 原文示例片段结束 ---

int main()
{
    Database* d { createDatabase("test.db") };
    if (d == nullptr)
        std::cout << "createDatabase() returned a null pointer\n";
    else
        std::cout << "Database created\n";

    return 0;
}
