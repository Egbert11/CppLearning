// ============================================================
// 来源小节：18.2 Introduction to iterators
// 示例说明：用泛型的 std::begin()/std::end()（<iterator> 中提供）取得首尾
//           迭代器，效果与成员函数版相同。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-iterators/
// 预期输出：1 2 3
// 备注：本节代码为按原文描述重建。
// 提示：对 C 风格数组 std::begin/std::end 定义在 <iterator>；对支持迭代器的
//       容器，它们定义在容器自己的头文件中（如 <array>、<vector>）。
// ============================================================
#include <array>
#include <iostream>
#include <iterator> // For std::begin and std::end

int main()
{
    std::array array{ 1, 2, 3 };

    // Use std::begin and std::end to get the begin and end points.
    auto begin{ std::begin(array) };
    auto end{ std::end(array) };

    for (auto p{ begin }; p != end; ++p) // ++ to move to next element
    {
        std::cout << *p << ' '; // dereference to get value of current element
    }
    std::cout << '\n';

    return 0;
}
