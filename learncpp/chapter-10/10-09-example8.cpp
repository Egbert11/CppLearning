// 来源小节：10.9 Type deduction for functions
// 示例说明：用尾置返回类型让连续的函数声明整齐对齐。（对应原文示例 8）
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-for-functions/
//
// 编译：g++ -std=c++20 -Wall 10-09-example8.cpp -o a
// 预期输出：
//   11
//   2.5
//   hi there
//   world
//
// 本节代码为按原文描述重建。

#include <iostream>
#include <string>
#include <string_view>
#include <type_traits>

// --- 原文示例片段（声明对齐） ---
auto add(int x, int y) -> int;
auto divide(double x, double y) -> double;
auto printSomething() -> void;
auto generateSubstring(std::string_view s, int start, int len) -> std::string;
// --- 原文示例片段结束 ---

// 为可运行而补上定义（语义与原文一致）
auto add(int x, int y) -> int { return x + y; }
auto divide(double x, double y) -> double { return x / y; }
auto printSomething() -> void { std::cout << "hi there\n"; }
auto generateSubstring(std::string_view s, int start, int len) -> std::string
{
    return std::string{ s.substr(start, len) };
}

int main()
{
    std::cout << add(5, 6) << '\n';
    std::cout << divide(5.0, 2.0) << '\n';
    printSomething();
    std::cout << generateSubstring("hello world", 6, 5) << '\n';

    return 0;
}
