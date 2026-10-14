// ============================================================
// 来源小节：14.13 Temporary class objects
// 示例说明：把 std::string_view 传给接受 const std::string& 的函数——
//           sv 不能隐式转换为 std::string，需显式创建临时 string。
//           三种可行写法：static_cast<std::string>(sv)、std::string { sv }、
//           std::string ( sv )（C 风格转换，应避免）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/temporary-class-objects/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include "printString.h"

#include <iostream>
#include <string>
#include <string_view>

int main()
{
    std::string_view sv{ "Hello" };

    // printString(sv); // compile error: no implicit conversion from std::string_view to std::string

    // --- 原文示例片段（原 Example 16）---
    printString( static_cast<std::string>(sv) ); // case 1: create a temporary std::string
    printString( std::string { sv } );           // case 2: create a temporary std::string
    printString( std::string ( sv ) );           // case 3: C-style cast -- avoid this one!
    // --- 原文示例片段结束 ---

    std::cout << '\n';

    return 0;
}

// 预期输出：
// HelloHelloHello
