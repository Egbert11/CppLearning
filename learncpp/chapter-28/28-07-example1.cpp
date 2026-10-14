// ============================================================
// 来源小节：28.7 Random file I/O（原示例 3：seekg() 演示程序）
// 示例说明：用 seekg() 移动文件指针：先移到第 5 个字符读一行，再向前 8 字节
//           读一行，最后从末尾前 14 字节读一行。
// 原文链接：https://www.learncpp.com/cpp-tutorial/random-file-io/
// 预期输出（假设 Sample.txt 为 4 行 "This is line N"）：
//   is line 1
//   line 2
//   This is line 4
//   原文注明第三行会随文件编码不同而不同；最后一次读取被原文标为 undefined behavior。
// 备注：代码取自原文 HTML 逐字抽取（<pre> 块）。运行前需存在 Sample.txt。
// ============================================================
#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::ifstream inf{ "Sample.txt" };

    // If we couldn't open the input file stream for reading
    if (!inf)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened for reading!\n";
        return 1;
    }

    std::string strData;

    inf.seekg(5); // move to 5th character
    // Get the rest of the line and print it, moving to line 2
    std::getline(inf, strData);
    std::cout << strData << '\n';

    inf.seekg(8, std::ios::cur); // move 8 more bytes into file
    // Get rest of the line and print it
    std::getline(inf, strData);
    std::cout << strData << '\n';

    inf.seekg(-14, std::ios::end); // move 14 bytes before end of file
    // Get rest of the line and print it
    std::getline(inf, strData); // undefined behavior
    std::cout << strData << '\n';

    return 0;
}
