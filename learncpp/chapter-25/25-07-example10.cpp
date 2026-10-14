// ---------------------------------------------------------------------------
// 来源小节：25.7 Pure virtual functions, abstract base classes, and interface classes
// 原文链接：https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-abstract-base-classes-and-interface-classes/
// 示例说明：接口类（interface class）没有成员变量、所有函数都是纯虚函数。
//           面向接口编程：mySqrt 依赖 IErrorLog 接口而非某个具体日志类，
//           调用者可以传入任意符合接口的类。
// 预期输出：
//   3
//   error: Tried to take square root of value less than 0
//   0
// 原文给出的是 IErrorLog 接口定义（逐字）与 mySqrt 依赖该接口的签名（逐字）；
// FileErrorLog 具体实现与 main() 为补充，用于让程序可完整运行。
// ---------------------------------------------------------------------------

#include <cmath> // for sqrt()
#include <iostream>
#include <string_view>

// --- 原文示例片段：接口类 IErrorLog ---
class IErrorLog
{
public:
    virtual bool openLog(std::string_view filename) = 0;
    virtual bool closeLog() = 0;

    virtual bool writeError(std::string_view errorMessage) = 0;

    virtual ~IErrorLog() {} // make a virtual destructor in case we delete an IErrorLog pointer, so the proper derived destructor is called
};

// --- 原文示例片段：mySqrt 依赖接口而非具体类 ---
double mySqrt(double value, IErrorLog& log)
{
    if (value < 0.0)
    {
        log.writeError("Tried to take square root of value less than 0");
        return 0.0;
    }

    return std::sqrt(value);
}

// --- 以下 具体实现 与 main() 为补充，用于演示程序可运行 ---
class FileErrorLog : public IErrorLog
{
public:
    bool openLog(std::string_view filename) override { std::cout << "opening " << filename << '\n'; return true; }
    bool closeLog() override { std::cout << "closing\n"; return true; }
    bool writeError(std::string_view errorMessage) override { std::cout << "error: " << errorMessage << '\n'; return true; }
};

int main()
{
    FileErrorLog log;
    std::cout << mySqrt(9.0, log) << '\n';
    std::cout << mySqrt(-4.0, log) << '\n';

    return 0;
}
