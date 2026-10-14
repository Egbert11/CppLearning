// ============================================================
// 来源小节：18.3 Introduction to standard library algorithms
// 示例说明：std::for_each——对区间内每个元素应用同一个函数，适合“对列表
//           中每一项重复同一操作”。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-standard-library-algorithms/
// 预期输出：2 4 6 8
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <algorithm>
#include <array>
#include <iostream>

void doubleNumber(int& i)
{
    i *= 2;
}

int main()
{
    std::array arr{ 1, 2, 3, 4 };

    std::for_each(arr.begin(), arr.end(), doubleNumber);

    for (int i : arr)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}
