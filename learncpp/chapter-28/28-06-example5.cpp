// ============================================================
// 来源小节：28.6 Basic file I/O（原 Example E）
// 示例说明：显式 close() 后用 open(..., std::ios::app) 重新打开同一文件，
//           再追加写入并再次关闭。
// 原文链接：https://www.learncpp.com/cpp-tutorial/basic-file-io/
// 预期：Sample.txt 得到第 1、2 行（覆盖写入）后追加第 3 行。
// 备注：原 Example E 是片段，这里包进 main() 并补 <fstream>/<iostream>。
//       代码取自原文 HTML 逐字抽取（<pre> 块）。
// ============================================================
#include <fstream>
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::ofstream outf{ "Sample.txt" };
    outf << "This is line 1\n";
    outf << "This is line 2\n";
    outf.close(); // explicitly close the file

    // Oops, we forgot something
    outf.open("Sample.txt", std::ios::app);
    outf << "This is line 3\n";
    outf.close();
    // --- 原文示例片段结束 ---

    return 0;
}
