// 来源小节：27.8 Exception dangers and downsides
// 示例说明："资源清理"陷阱（反例）——文件在 try 块内被打开、写入、关闭；若 writeFile 抛异常，
//           控制流直接跳到 catch，closeFile 永远不会执行，文件没有被关闭。
// 原文链接：https://www.learncpp.com/cpp-tutorial/exception-dangers-and-downsides/
// 预期输出：
//   Opened file data.txt
//   Failed to write to file: disk full
//   (closeFile was never called -> file leaked)
// 说明：FileException/openFile/writeFile/closeFile 的模拟实现为让片段可运行而补充。

#include <iostream>
#include <stdexcept>
#include <string>

// --- 为令原文片段可运行而补充的模拟实现（原文未提供） ---
struct FileException : std::runtime_error
{
    explicit FileException(const std::string& message) : std::runtime_error(message) {}
};

void openFile(const std::string& filename) { std::cout << "Opened file " << filename << '\n'; }
void writeFile(const std::string& /*filename*/, const std::string& /*data*/)
{
    throw FileException("disk full");
}
void closeFile(const std::string& filename) { std::cout << "Closed file " << filename << '\n'; }
// --- 模拟实现结束 ---

int main()
{
    const std::string filename{ "data.txt" };
    const std::string data{ "hello world" };

    // --- 原文示例片段 ---
    try
    {
        openFile(filename);
        writeFile(filename, data);
        closeFile(filename);
    }
    catch (const FileException& exception)
    {
        std::cerr << "Failed to write to file: " << exception.what() << '\n';
    }
    // --- 原文示例片段结束 ---

    std::cout << "(closeFile was never called -> file leaked)\n";
    return 0;
}
