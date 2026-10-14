// ============================================================
// 来源小节：13.2 Unscoped enumerations
// 示例说明：用"魔法数字"作为函数返回的错误码（-1/-2/-3）。含义全凭记忆和注释，
//           可读性差，也容易和真正的数值混淆。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unscoped-enumerations/
// 备注：本节代码为按原文描述忠实重建。原文中的 openFile/readFile/parseFile
//       是示意用的未定义函数，这里补上桩函数以便编译。
// ============================================================
// 桩函数：仅为了让示例可编译，原文假定它们存在
bool openFile()  { return true; }
bool readFile()  { return true; }
bool parseFile() { return true; }

int readFileContents()
{
    if (!openFile())
        return -1;
    if (!readFile())
        return -2;
    if (!parseFile())
        return -3;

    return 0; // success
}

int main()
{
    [[maybe_unused]] int result { readFileContents() };
    return 0;
}
