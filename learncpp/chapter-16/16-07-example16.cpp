// ============================================================
// 来源小节：16.7 Arrays, loops, and sign challenge solutions
// 示例说明：辅助函数 toUZ()——用 static_assert 限制为整数/枚举类型，
//           把有符号索引安全地转成 std::size_t。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arrays-loops-and-sign-challenge-solutions/
// 预期输出：9 1 2 8 3 7 6 4
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <cstddef>
#include <iostream>
#include <type_traits>
#include <vector>

template <typename T>
constexpr std::size_t toUZ(T value)
{
    static_assert(std::is_integral<T>() || std::is_enum<T>());
    return static_cast<std::size_t>(value);
}

int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

    for (auto index{ std::ssize(arr) - 1 }; index >= 0; --index)
        std::cout << arr[toUZ(index)] << ' ';

    std::cout << '\n';

    return 0;
}
