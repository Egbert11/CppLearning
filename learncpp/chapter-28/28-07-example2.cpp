// ============================================================
// 来源小节：28.7 Random file I/O（原示例 5：用 tellg() 求文件大小）
// 示例说明：先 seekg 到文件末尾，再用 tellg() 得到文件大小（字节数）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/random-file-io/
// 预期：原文在 Windows 上输出 64（含 CRLF）；用 LF 结尾时会是 56。
//       若文件带尾部零字节填充，结果也可能不同。
// 备注：代码取自原文 HTML 逐字抽取（<pre> 块），这里补 <iostream>。
//       运行前需存在 Sample.txt。本程序为演示，把结果打印出来。
// ============================================================
#include <fstream>
#include <iostream>

int main()
{
    std::ifstream inf {"Sample.txt"};
    inf.seekg(0, std::ios::end); // move to end of file
    std::cout << inf.tellg() << '\n'; // 原文示例直接输出 inf.tellg();

    return 0;
}
