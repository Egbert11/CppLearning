// ============================================================
// 来源小节：16.10 std::vector resizing and capacity
// 示例说明：用 resize() 把 vector 从 5 个元素缩小到 3 个：
//           尾部的元素被丢弃，保留下来的前三个值不变。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdvector-resizing-and-capacity/
// 预期输出：
//   The length is: 5
//   The length is: 3
//   0 1 2
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

void printLength(const std::vector<int>& v)
{
    std::cout << "The length is: " << v.size() << '\n';
}

int main()
{
    std::vector v { 0, 1, 2, 3, 4 };
    printLength(v);

    v.resize(3); // resize to 3 elements

    printLength(v);

    for (auto e : v)
        std::cout << e << ' ';
    std::cout << '\n';

    return 0;
}
