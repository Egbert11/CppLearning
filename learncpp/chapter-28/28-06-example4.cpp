// ============================================================
// 来源小节：28.6 Basic file I/O（原 Example D）
// 示例说明：用 std::ios::app 模式追加写入 Sample.txt 的第 3、4 行。
// 原文链接：https://www.learncpp.com/cpp-tutorial/basic-file-io/
// 预期：Sample.txt 在原有两行之后追加：
//   This is line 3
//   This is line 4
// 备注：代码取自原文 HTML 逐字抽取（<pre> 块）。运行前需存在 Sample.txt。
// ============================================================
#include <iostream>
#include <fstream>

int main()
{
    // We'll pass the ios:app flag to tell the ofstream to append
    // rather than rewrite the file. We do not need to pass in std::ios::out
    // because ofstream defaults to std::ios::out
    std::ofstream outf{ "Sample.txt", std::ios::app };

    // If we couldn't open the output file stream for writing
    if (!outf)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened for writing!\n";
        return 1;
    }

    outf << "This is line 3\n";
    outf << "This is line 4\n";

    return 0;

    // When outf goes out of scope, the ofstream
    // destructor will close the file
}
