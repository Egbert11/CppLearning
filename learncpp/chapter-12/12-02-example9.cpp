// ============================================================
// 来源小节：12.2 Value categories (lvalues and rvalues)
// 示例说明：用重载检测值类别——以 T& 接受左值、T&& 接受右值，让
//           编译器替我们判断每个表达式是左值还是右值，并打印出来。
// 原文链接：https://www.learncpp.com/cpp-tutorial/value-categories-lvalues-and-rvalues/
// 备注：本节代码为按原文描述忠实重建（对应原文 Example 13）。
//       术语说明：这里用到的 T&& 是"右值引用"（C++11 引入），尚未讲
//       到，此处仅作为检测手段；本章后续会讲左值引用（12.3）。
// ============================================================
#include <iostream>
#include <string>

// returns true if the argument resolves to an lvalue, false if it resolves to an rvalue
template <typename T>
bool is_lvalue(T&)
{
    return true;
}

template <typename T>
bool is_lvalue(T&&)
{
    return false;
}

#define PRINTVCAT(expr) { std::cout << #expr << " is an " << (is_lvalue(expr) ? "lvalue\n" : "rvalue\n"); }

int getint()
{
    return 5;
}

int main()
{
    // --- 原文示例片段 ---
    PRINTVCAT(5);
    PRINTVCAT(getint());

    int x { 5 };

    PRINTVCAT(x);
    PRINTVCAT(std::string {"Hello"});
    PRINTVCAT("Hello");
    PRINTVCAT(++x);
    PRINTVCAT(x++);
    // --- 原文示例片段结束 ---

    return 0;
}

// 预期输出：
// 5 is an rvalue
// getint() is an rvalue
// x is an lvalue
// std::string {"Hello"} is an rvalue
// "Hello" is an lvalue
// ++x is an lvalue
// x++ is an rvalue
