// ============================================================
// 来源小节：12.15 std::optional
// 示例说明：用 std::optional 实现可选参数。与指针版本相比，它按值（复制）
//           传递，因此可以接受右值，例如字面量 62。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdoptional/
// 备注：本节代码为按原文描述忠实重建（原 Example 10）。
//       原文形参写作 std::optional<const int>；为便于 constexpr 之外的赋值
//       与转换，这里使用 std::optional<int>（语义一致）。
// ============================================================
#include <iostream>
#include <optional>

void printIDNumber(std::optional<int> id = std::nullopt)
{
    if (id)
        std::cout << "Your ID number is " << *id << ".\n";
    else
        std::cout << "Your ID number is not known.\n";
}

int main()
{
    printIDNumber(); // we don't know the user's ID yet

    int userid { 34 };
    printIDNumber(userid); // we know the user's ID now

    printIDNumber(62); // now also works with rvalue arguments

    return 0;
}
