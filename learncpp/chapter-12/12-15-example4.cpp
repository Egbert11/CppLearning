// ============================================================
// 来源小节：12.15 std::optional
// 示例说明：返回 std::optional<int>。函数可能返回值、也可能不返回值；成功
//           时用 `return x / y` 隐式包装，失败时用 `return {}`（或
//           std::nullopt）返回空。调用方先判断是否含值，再解引用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdoptional/
// 预期输出：
//   Result 1: 4
//   Result 2: failed
// 备注：本节代码为按原文描述忠实重建（原 Example 4）。
// ============================================================
#include <iostream>
#include <optional> // for std::optional

std::optional<int> doIntDivision(int x, int y)
{
    if (y == 0)
        return {}; // or return std::nullopt

    return x / y;
}

int main()
{
    std::optional<int> result1 { doIntDivision(20, 5) };
    if (result1) // if result1 has a value
        std::cout << "Result 1: " << *result1 << '\n'; // dereference the optional
    else
        std::cout << "Result 1: failed\n";

    std::optional<int> result2 { doIntDivision(5, 0) };
    if (result2) // if result2 has a value
        std::cout << "Result 2: " << *result2 << '\n'; // dereference the optional
    else
        std::cout << "Result 2: failed\n";

    return 0;
}
