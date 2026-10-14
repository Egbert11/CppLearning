// ============================================================
// 来源小节：18.2 Introduction to iterators
// 示例说明：直接用容器的成员函数 begin()/end() 取得迭代器来遍历 std::array。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-iterators/
// 预期输出：1 2 3
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <array>
#include <iostream>

int main()
{
    std::array array{ 1, 2, 3 };

    // Ask our array for the begin and end points (via the begin and end member functions).
    auto begin{ array.begin() };
    auto end{ array.end() };

    for (auto p{ begin }; p != end; ++p) // ++ to move to next element.
    {
        std::cout << *p << ' '; // dereference to get value of current element.
    }
    std::cout << '\n';

    return 0;
}
