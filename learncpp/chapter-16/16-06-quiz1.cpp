// ============================================================
// 来源小节：16.6 Arrays and loops
// 示例说明：Quiz #1 解答——用循环打印数组所有元素，并在非空时补一个换行。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arrays-and-loops/
// 预期输出：4 6 7 3 8 2 1 9
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

    for (std::size_t index{ 0 }; index < arr.size(); ++index)
        std::cout << arr[index] << ' ';

    if (arr.size() > 0)
        std::cout << '\n';

    return 0;
}
