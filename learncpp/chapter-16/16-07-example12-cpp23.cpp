// ============================================================
// 来源小节：16.7 Arrays, loops, and sign challenge solutions
// 示例说明：C++23 的 Z 字面量后缀——`0Z` 直接得到一个有符号大整数类型的 0，
//           省去 static_cast，配合 auto 使用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arrays-loops-and-sign-challenge-solutions/
// 预期输出：4 6 7 3 8 2 1 9
// 备注：本文件需要 C++23（g++ -std=c++23），后缀约定为 -cpp23。
//       本节代码为按原文描述重建。
// ============================================================
#include <cstddef>
#include <iostream>
#include <vector>

int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

    for (auto index{ 0Z }; index < static_cast<std::ptrdiff_t>(arr.size()); ++index)
        std::cout << arr[static_cast<std::size_t>(index)] << ' ';

    std::cout << '\n';

    return 0;
}
