// ============================================================
// 来源小节：13.2 Unscoped enumerations
// 示例说明：用枚举 FileReadResult 代替魔法数字错误码，返回值和调用处的判断
//           都变得自解释。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unscoped-enumerations/
// 备注：本节代码为按原文描述忠实重建。桩函数同 example7。
// ============================================================
#include <iostream>

// 桩函数：仅为了让示例可编译，原文假定它们存在
bool openFile()  { return true; }
bool readFile()  { return true; }
bool parseFile() { return true; }

enum FileReadResult
{
    readResultSuccess,
    readResultErrorFileOpen,
    readResultErrorFileRead,
    readResultErrorFileParse,
};

FileReadResult readFileContents()
{
    if (!openFile())
        return readResultErrorFileOpen;
    if (!readFile())
        return readResultErrorFileRead;
    if (!parseFile())
        return readResultErrorFileParse;

    return readResultSuccess;
}

int main()
{
    if (readFileContents() == readResultSuccess)
        std::cout << "File read successfully\n";
    else
        std::cout << "Error reading file\n";

    return 0;
}

// 预期输出：
// File read successfully
