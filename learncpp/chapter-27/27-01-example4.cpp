// ============================================================
// 来源小节：27.1 The need for exceptions
// 示例说明：从配置文件读取若干参数时，每读一个值就要检查一次错误并返回错误码，
//           于是"错误检查代码"和"正常逻辑"纠缠在一起。原文以此强调返回码方案
//           在长流程中的笨重（每加一个参数就要多一段检查样板代码）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-need-for-exceptions/
// 预期输出：ERROR_OPENING_FILE （因仓库内不存在 setup.ini，直接返回此错误码）
// 备注：原文该段为片段（用到未定义的 enum 与 readXxxFromFile 辅助函数）。这里
//       把它们补齐，重建为可编译运行的完整程序，核心片段用注释标出边界。
// ============================================================
#include <fstream>
#include <iostream>
#include <string>

enum Error
{
    ERROR_OPENING_FILE,
    ERROR_READING_VALUE, // 结合原文语境给出的枚举项
    SUCCESS,
};

// 读取辅助函数：成功返回 true，失败返回 false（原文未给出实现，这里按语义重建）
static bool readIntegerFromFile(std::ifstream& in, int& out)
{
    return static_cast<bool>(in >> out);
}
static bool readDoubleFromFile(std::ifstream& in, double& out)
{
    return static_cast<bool>(in >> out);
}
static bool readFloatFromFile(std::ifstream& in, float& out)
{
    return static_cast<bool>(in >> out);
}

Error loadParameters()
{
    int m_firstParameter {};
    double m_secondParameter {};
    float m_thirdParameter {};

    // --- 原文示例片段开始 ---
    std::ifstream setupIni { "setup.ini" }; // open setup.ini for reading
    // If the file couldn't be opened (e.g. because it was missing) return some error enum
    if (!setupIni)
        return ERROR_OPENING_FILE;

    // Now read a bunch of values from a file
    if (!readIntegerFromFile(setupIni, m_firstParameter)) // try to read an integer from the file
        return ERROR_READING_VALUE; // Return enum value indicating value couldn't be read

    if (!readDoubleFromFile(setupIni, m_secondParameter)) // try to read a double from the file
        return ERROR_READING_VALUE;

    if (!readFloatFromFile(setupIni, m_thirdParameter)) // try to read a float from the file
        return ERROR_READING_VALUE;
    // --- 原文示例片段结束 ---

    return SUCCESS;
}

int main()
{
    Error e { loadParameters() };
    if (e == ERROR_OPENING_FILE)
        std::cout << "ERROR_OPENING_FILE\n";
    else if (e == ERROR_READING_VALUE)
        std::cout << "ERROR_READING_VALUE\n";
    else
        std::cout << "SUCCESS\n";

    return 0;
}
