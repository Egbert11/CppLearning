// ============================================================
// 来源小节：17.x Chapter 17 summary and quiz（测验 1(a)）
// 示例说明：一段有 bug 的代码——循环条件误用 <=，导致越界读取。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-17-summary-and-quiz/
// 后缀：-ub。arr 只有 4 个元素，count 会取到 4，访问 arr[4] 属越界（未定义行为）。
// 修法：把 count <= std::size(arr) 改为 count < std::size(arr)。
// ============================================================
#include <array>
#include <iostream>

int main()
{
    std::array arr { 0, 1, 2, 3 };

    for (std::size_t count { 0 }; count <= std::size(arr); ++count) // bug: should be < (not <=)
        std::cout << arr[count] << ' ';

    return 0;
}
