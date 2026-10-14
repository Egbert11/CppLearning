// ============================================================
// 来源小节：18.2 Introduction to iterators
// 示例说明：范围 for 循环遍历 std::array——它内部正是通过迭代器实现的，
//           写起来最简单。凡是可用 begin()/end() 或 std::begin/std::end 的
//           容器/数组都能这样遍历。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-iterators/
// 预期输出：1 2 3
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <array>
#include <iostream>

int main()
{
    std::array array{ 1, 2, 3 };

    // This does exactly the same as the loop we used before.
    for (int i : array)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}
