// ============================================================
// 来源小节：12.15 std::optional
// 示例说明：检查 optional 是否含值：调用 has_value()，或依赖到 bool 的隐式
//           转换。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdoptional/
// 备注：本节代码为按原文描述忠实重建（原 Example 6）。
// ============================================================
#include <iostream>
#include <optional>

int main()
{
    std::optional<int> o1 { 5 };
    std::optional<int> o2 {};

    if (o1.has_value()) // call has_value() to check if o1 has a value
        std::cout << "o1 has a value\n";

    if (o2) // use implicit conversion to bool to check if o2 has a value
        std::cout << "o2 has a value\n";
    else
        std::cout << "o2 has no value\n";

    return 0;
}
