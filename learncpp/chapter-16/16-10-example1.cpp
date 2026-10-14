// ============================================================
// 来源小节：16.10 std::vector resizing and capacity
// 示例说明：用 resize() 把 vector 从 3 个元素调大到 5 个：
//           已有元素的值保留，新增的两个 int 被值初始化（零初始化）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdvector-resizing-and-capacity/
// 预期输出：
//   The length is: 3
//   The length is: 5
//   0 1 2 0 0
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    std::vector v { 0, 1, 2 };
    std::cout << "The length is: " << v.size() << '\n';

    v.resize(5); // resize to 5 elements

    std::cout << "The length is: " << v.size() << '\n';

    for (auto e : v)
        std::cout << e << ' ';
    std::cout << '\n';

    return 0;
}
