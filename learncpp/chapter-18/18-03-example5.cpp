// ============================================================
// 来源小节：18.3 Introduction to standard library algorithms
// 示例说明：Tip——降序非常常见，C++ 在 <functional> 中提供了现成类型
//           std::greater，可替代自定义的 greater 函数。因为它是“类型”而非
//           可调用函数，所以要用花括号实例化：std::greater{}（C++17 起可省略
//           元素类型；此前需写 std::greater<int>{}）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-standard-library-algorithms/
// 预期输出：99 90 80 40 13 5
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <algorithm>
#include <array>
#include <functional> // for std::greater
#include <iostream>

int main()
{
    std::array arr{ 13, 90, 99, 5, 40, 80 };

    // std::greater{} is a type, so it must be instantiated with braces (C++17).
    std::sort(arr.begin(), arr.end(), std::greater{}); // descending
    // Before C++17 you had to specify the element type explicitly:
    // std::sort(arr.begin(), arr.end(), std::greater<int>{});

    for (int i : arr)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}
