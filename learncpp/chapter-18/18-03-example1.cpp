// ============================================================
// 来源小节：18.3 Introduction to standard library algorithms
// 示例说明：std::find 查找并替换。std::find 接受起始迭代器、结束迭代器和
//           要查找的值，返回指向首个匹配元素的迭代器；找不到则返回 end 迭代器。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-standard-library-algorithms/
// 预期输出（输入 `5 234`）：13 90 99 234 40 80
// 预期输出（输入 `0 234`）：Could not find 0 回车 13 90 99 5 40 80
// 备注：本节代码为按原文描述重建；原示例省略了输入校验。
// ============================================================
#include <algorithm>
#include <array>
#include <iostream>

int main()
{
    std::array arr{ 13, 90, 99, 5, 40, 80 };

    std::cout << "Enter a value to search for and replace with: ";
    int search{};
    int replace{};
    std::cin >> search >> replace;

    // Input validation omitted

    // std::find returns an iterator (its type can be deduced with auto)
    auto found{ std::find(arr.begin(), arr.end(), search) };

    // Algorithms that don't find what they're looking for return the end iterator
    if (found == arr.end())
    {
        std::cout << "Could not find " << search << '\n';
    }
    else
    {
        *found = replace;
    }

    for (int i : arr)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}
