// ============================================================
// 来源小节：18.3 Introduction to standard library algorithms
// 示例说明：std::find_if 按条件查找。当需要的不是“完全相等”而是一个判断
//           条件（如子串匹配）时，传入一个可调用对象（谓词），它会对每个元素
//           调用并返回 true/false。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-standard-library-algorithms/
// 预期输出：Found walnut
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

// Our function will return true if the element matches
bool containsNut(std::string_view str)
{
    // std::string_view::find returns std::string_view::npos if it doesn't find
    // the substring. Otherwise it returns the index where the substring occurs
    // in str.
    return str.find("nut") != std::string_view::npos;
}

int main()
{
    std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };

    // Scan the array to find the first element that contains "nut".
    auto found{ std::find_if(arr.begin(), arr.end(), containsNut) };

    if (found == arr.end())
    {
        std::cout << "No nuts\n";
    }
    else
    {
        std::cout << "Found " << *found << '\n';
    }

    return 0;
}
