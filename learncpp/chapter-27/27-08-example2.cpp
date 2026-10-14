// 来源小节：27.8 Exception dangers and downsides
// 示例说明：修正版——把 closeFile 放到 try/catch 之后，无论是否发生异常文件都会被关闭。
// 原文链接：https://www.learncpp.com/cpp-tutorial/exception-dangers-and-downsides/
// 预期输出：
//   Opened file data.txt
//   Failed to write to file: disk full
//   Closed file data.txt
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
    }
    catch (const FileException& exception)
    {
        std::cerr << "Failed to write to file: " << exception.what() << '\n';
    }

    // Make sure file is closed
    closeFile(filename);
    // --- 原文示例片段结束 ---

    return 0;
}
