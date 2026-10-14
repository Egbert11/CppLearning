// ============================================================
// 来源小节：12.15 std::optional
// 示例说明：取出 optional 中的值：`*o` 解引用（若为空则是未定义行为）、
//           `o.value()` 取值（若为空则抛出 std::bad_optional_access）、
//           `o.value_or(default)` 在空时返回默认值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdoptional/
// 预期输出：
//   5
//   3
//   42
// 备注：本节代码为按原文描述忠实重建（原 Example 7）。
//       为便于演示，o1、o2 均含值，o3 为空；对空 optional 解引用是 UB、
//       对空 optional 调用 value() 会抛出 std::bad_optional_access。
// ============================================================
#include <iostream>
#include <optional>

int main()
{
    std::optional<int> o1 { 5 }; // has a value
    std::optional<int> o2 { 3 }; // has a value
    std::optional<int> o3 {};    // no value

    std::cout << *o1 << '\n';             // dereference to get value (safe: o1 has a value)
    std::cout << o2.value() << '\n';      // .value() (would throw std::bad_optional_access if empty)
    std::cout << o3.value_or(42) << '\n'; // value_or() returns the default if empty

    // std::cout << *o3 << '\n';   // undefined behavior: o3 is empty
    // std::cout << o3.value();    // throws std::bad_optional_access

    return 0;
}
