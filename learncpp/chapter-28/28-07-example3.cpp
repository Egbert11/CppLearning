// ============================================================
// 来源小节：28.7 Random file I/O（原示例 7：把元音替换为 '#'）
// 示例说明：用 std::fstream（in | out）逐字符遍历文件；遇到元音就回退一个字符、
//           写 '#' 覆盖它，再 seek 到当前位置以切回读模式，使下一次 get() 正常。
// 原文链接：https://www.learncpp.com/cpp-tutorial/random-file-io/
// 预期：Sample.txt 中所有元音（a e i o u，含大写）被替换为 '#'，如：
//   Th#s #s l#n# 1
//   ...
// 备注：代码取自原文 HTML 逐字抽取（<pre> 块）。运行前需存在 Sample.txt；
//       该程序会就地修改它。
// ============================================================
#include <fstream>
#include <iostream>
#include <string>

int main()
{
    // Note we have to specify both in and out because we're using fstream
    std::fstream iofile{ "Sample.txt", std::ios::in | std::ios::out };

    // If we couldn't open iofile, print an error
    if (!iofile)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened!\n";
        return 1;
    }

    char chChar{}; // we're going to do this character by character

    // While there's still data to process
    while (iofile.get(chChar))
    {
        switch (chChar)
        {
            // If we find a vowel
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':

                // Back up one character
                iofile.seekg(-1, std::ios::cur);

                // Because we did a seek, we can now safely do a write, so
                // let's write a # over the vowel
                iofile << '#';

                // Now we want to go back to read mode so the next call
                // to get() will perform correctly.  We'll seekg() to the current
                // location because we don't want to move the file pointer.
                iofile.seekg(iofile.tellg(), std::ios::beg);

                break;
        }
    }

    return 0;
}
