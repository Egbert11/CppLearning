// ============================================================
// 来源小节：18.1 Sorting an array using selection sort
// 示例说明：用标准库 std::sort（<algorithm>）排序同一个数组——它接受
//           begin/end 迭代器，默认按 operator< 升序排序。
// 原文链接：https://www.learncpp.com/cpp-tutorial/sorting-an-array-using-selection-sort/
// 预期输出：10 20 30 40 50
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <algorithm> // for std::sort
#include <array>
#include <iostream>
#include <iterator> // for std::begin, std::end

int main()
{
    std::array<int, 5> array{ 30, 50, 20, 10, 40 };

    std::sort(std::begin(array), std::end(array));

    for (int i : array)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}
