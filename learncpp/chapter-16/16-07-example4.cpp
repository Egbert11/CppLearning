// ============================================================
// 来源小节：16.7 Arrays, loops, and sign challenge solutions
// 示例说明：在 main 里直接用 std::vector<int>::size_type 作循环变量。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arrays-loops-and-sign-challenge-solutions/
// 预期输出：4 6 7 3 8 2 1 9
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

    for (std::vector<int>::size_type index { 0 }; index < arr.size(); ++index)
        std::cout << arr[index] << ' ';

    std::cout << '\n';

    return 0;
}
