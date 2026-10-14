// ============================================================
// 来源小节：18.2 Introduction to iterators
// 示例说明：用指针遍历数组：begin 指向首元素，end = begin + 元素个数
//           （指向最后一个元素之后的位置），循环中 ++ 前进、* 解引用取值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-iterators/
// 预期输出：0 1 2 3 4 5 6
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <array>
#include <iostream>

int main()
{
    std::array arr{ 0, 1, 2, 3, 4, 5, 6 };

    auto begin{ &arr[0] };
    // note that this points to one spot beyond the last element
    auto end{ begin + std::size(arr) };

    // for-loop with pointer
    for (auto ptr{ begin }; ptr != end; ++ptr) // ++ to move to next element
    {
        std::cout << *ptr << ' '; // dereference to get value of current element
    }
    std::cout << '\n';

    return 0;
}
