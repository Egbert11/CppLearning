// ============================================================
// 来源小节：12.15 std::optional
// 示例说明：构造 std::optional 的三种方式：带值、空花括号、std::nullopt。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdoptional/
// 备注：本节代码为按原文描述忠实重建（原 Example 5）。
// ============================================================
#include <optional>

int main()
{
    std::optional<int> o1 { 5 };            // initialize with a value
    std::optional<int> o2 {};               // initialize with no value
    std::optional<int> o3 { std::nullopt }; // initialize with no value

    return static_cast<int>(o1.has_value()) + static_cast<int>(o2.has_value())
         + static_cast<int>(o3.has_value());
}
