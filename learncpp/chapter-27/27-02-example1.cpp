// ============================================================
// 来源小节：27.2 Basic exception handling
// 示例说明：throw 后面可以跟任意数据类型的值——整数、枚举、C 风格字符串、
//           已有的 double 变量，或自定义异常类对象。每一条都表示"发生了需要
//           处理的错误"。下面五行 throw 语句取自原文。
// 原文链接：https://www.learncpp.com/cpp-tutorial/basic-exception-handling/
// 预期输出：We caught an int exception with value: -1
// 备注：原文这五行是并列的语法展示。真正运行时只有第一条被执行（其余在其后
//       不可达，仅为完整展示语法而保留）；main 捕获 int 异常以正常结束程序。
// ============================================================
#include <iostream>

enum ErrorCode
{
    ENUM_INVALID_INDEX, // 供示例 throw 使用的枚举值
};

class MyException
{
public:
    explicit MyException(const char* /*what*/) {}
};

double dX { 5.0 }; // a double variable that was previously defined

void demonstrateThrows()
{
    throw -1; // throw a literal integer value
    throw ENUM_INVALID_INDEX; // throw an enum value
    throw "Can not take square root of negative number"; // throw a literal C-style (const char*) string
    throw dX; // throw a double variable that was previously defined
    throw MyException("Fatal Error"); // Throw an object of class MyException
}

int main()
{
    try
    {
        demonstrateThrows();
    }
    catch (int x)
    {
        std::cerr << "We caught an int exception with value: " << x << '\n';
    }

    return 0;
}
