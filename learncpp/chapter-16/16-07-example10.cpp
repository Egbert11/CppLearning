// ============================================================
// 来源小节：16.7 Arrays, loops, and sign challenge solutions
// 示例说明：自定义有符号别名 `using Index = std::ptrdiff_t;`，
//           长度转成 Index 再比较；下标访问时再转回 std::size_t。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arrays-loops-and-sign-challenge-solutions/
// 预期输出：4 6 7 3 8 2 1 9
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <cstddef>
#include <iostream>
#include <vector>

using Index = std::ptrdiff_t;

int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

    for (Index index{ 0 }; index < static_cast<Index>(arr.size()); ++index)
        std::cout << arr[static_cast<std::size_t>(index)] << ' ';

    std::cout << '\n';

    return 0;
}
