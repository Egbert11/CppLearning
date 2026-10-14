// ============================================================
// 来源小节：28.6 Basic file I/O（原 Example C）
// 示例说明：改用 std::getline(inf, strInput) 按“行”读取 Sample.txt。
// 原文链接：https://www.learncpp.com/cpp-tutorial/basic-file-io/
// 预期输出：
//   This is line 1
//   This is line 2
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

    // If we couldn't open the input file stream for reading
    if (!inf)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened for reading!\n";
        return 1;
    }

    // While there's still stuff left to read
    std::string strInput{};
    while (std::getline(inf, strInput))
	std::cout << strInput << '\n';

    return 0;

    // When inf goes out of scope, the ifstream
    // destructor will close the file
}
