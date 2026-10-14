// ============================================================
// 来源小节：18.3 Introduction to standard library algorithms
// 示例说明：std::count / std::count_if 统计满足条件的元素个数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-standard-library-algorithms/
// 预期输出：Counted 2 nut(s)
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

bool containsNut(std::string_view str)
{
    return str.find("nut") != std::string_view::npos;
}

int main()
{
    std::array<std::string_view, 5> arr{ "apple", "banana", "walnut", "lemon", "peanut" };

    auto nuts{ std::count_if(arr.begin(), arr.end(), containsNut) };

    std::cout << "Counted " << nuts << " nut(s)\n";

    return 0;
}
