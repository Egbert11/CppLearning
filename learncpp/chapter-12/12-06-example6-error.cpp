// ============================================================
// 来源小节：12.6 Pass by const lvalue reference
// 示例说明：把 std::string、std::string_view、C 风格字面量分别传给
//           std::string_view 形参与 const std::string& 形参。
//           string_view 形参对三种实参都廉价；const std::string& 形参
//           只对 std::string 实参廉价，string_view 实参无法隐式转换。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pass-by-const-lvalue-reference/
// !! -error：预期编译失败，勿修复。
//   预期错误：printS(sv) 处 cannot convert 'std::string_view' to
//             'const std::string&'（无隐式转换）。
// 备注：本节代码为按原文描述忠实重建（原 Example 6）。
//       除该错误行外其余调用均可编译；错误行存在故整文件预期编译失败。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

void printSV(std::string_view sv)
{
    std::cout << sv << '\n';
}

void printS(const std::string& s)
{
    std::cout << s << '\n';
}

int main()
{
    std::string s{ "Hello, world" };
    std::string_view sv { s };

    // Pass to `std::string_view` parameter
    printSV(s);              // ok: inexpensive conversion from std::string to std::string_view
    printSV(sv);             // ok: inexpensive copy of std::string_view
    printSV("Hello, world"); // ok: inexpensive conversion of C-style string literal to std::string_view

    // pass to `const std::string&` parameter
    printS(s);              // ok: inexpensive bind to std::string argument
    printS(sv);             // compile error: cannot implicit convert std::string_view to std::string
    printS(static_cast<std::string>(sv)); // bad: expensive creation of std::string temporary
    printS("Hello, world"); // bad: expensive creation of std::string temporary

    return 0;
}
