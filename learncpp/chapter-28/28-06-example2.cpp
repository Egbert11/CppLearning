// ============================================================
// 来源小节：28.6 Basic file I/O（原 Example B）
// 示例说明：用 std::ifstream + 提取运算符 >> 读取 Sample.txt；>> 遇空白即停，
//           所以是按“词”读取的。
// 原文链接：https://www.learncpp.com/cpp-tutorial/basic-file-io/
// 预期输出（每个词单独一行）：
//   This
//   is
//   line
//   1
//   This
//   is
//   line
//   2
// 备注：代码取自原文 HTML 逐字抽取（<pre> 块）。运行前需存在 Sample.txt
//       （可由 example1 生成）。
// ============================================================
#include <fstream>
#include <iostream>
#include <string>

int main()
{
    // ifstream is used for reading files
    // We'll read from a file called Sample.txt
    std::ifstream inf{ "Sample.txt" };

    // If we couldn't open the output file stream for reading
    if (!inf)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened for reading!\n";
        return 1;
    }

    // While there's still stuff left to read
    std::string strInput{};
    while (inf >> strInput)
        std::cout << strInput << '\n';

    return 0;

    // When inf goes out of scope, the ifstream
    // destructor will close the file
}
