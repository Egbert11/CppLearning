// ============================================================
// 来源小节：28.6 Basic file I/O（原 Example A）
// 示例说明：用 std::ofstream 打开/创建 Sample.txt 并写入两行；用 if (!outf)
//           检查是否成功打开。
// 原文链接：https://www.learncpp.com/cpp-tutorial/basic-file-io/
// 预期：在程序工作目录生成 Sample.txt，内容为：
//   This is line 1
//   This is line 2
// 备注：代码取自原文 HTML 逐字抽取（<pre> 块）。重复运行会完全覆盖该文件。
// ============================================================
#include <fstream>
#include <iostream>

int main()
{
    // ofstream is used for writing files
    // We'll make a file called Sample.txt
    std::ofstream outf{ "Sample.txt" };

    // If we couldn't open the output file stream for writing
    if (!outf)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened for writing!\n";
        return 1;
    }

    // We'll write two lines into this file
    outf << "This is line 1\n";
    outf << "This is line 2\n";

    return 0;

    // When outf goes out of scope, the ofstream
    // destructor will close the file
}
