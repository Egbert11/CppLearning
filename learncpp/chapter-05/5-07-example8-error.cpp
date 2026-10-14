// 来源小节：5.7 Introduction to std::string
// 示例说明：constexpr std::string 在 C++17 及更早不支持；C++20 也只在极有限情形可用。
//           应改用 std::string_view。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring/
//
// ※※※ 说明 ※※※
// 本节示例为按原文描述重建（对应原文 Example 15）。
// 原示例中的 `constexpr std::string name{ "Alex"s };` 是【编译错误】，
// 为让本文件可通过编译，该行以注释保留（见下方）。取消注释即会重现编译错误。
// 需要 C++23 特性：constexpr std::string 只在 C++23（且非常受限）下才有条件可用；
// 本仓库使用 C++20，因此仅以注释保留。

#include <string>

int main()
{
    using namespace std::string_literals;

    // constexpr std::string name{ "Alex"s }; // compile error: constexpr std::string not supported here (needs C++23, very limited)

    return 0;
}
