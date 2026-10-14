// ============================================================
// 来源小节：16.10 std::vector resizing and capacity
// 示例说明：把 5 个元素的 vector 先缩到 3、再长回 5。由于容量始终是 5，
//           两次 resize 都不会触发重新分配；长回 5 时新增元素再次被值初始化。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdvector-resizing-and-capacity/
// 预期输出（原作者机器上的结果，可能因实现而异）：
//   Capacity: 5  Length: 5
//   0 1 2 3 4
//   Capacity: 5  Length: 3
//   0 1 2
//   Capacity: 5  Length: 5
//   0 1 2 0 0
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

void printCapLen(const std::vector<int>& v)
{
    std::cout << "Capacity: " << v.capacity() << "  Length: " << v.size() << '\n';
}

int main()
{
    std::vector v { 0, 1, 2, 3, 4 };
    printCapLen(v);

    for (auto i : v)
        std::cout << i << ' ';
    std::cout << '\n';

    v.resize(3); // shrink to 3 elements
    printCapLen(v);

    for (auto i : v)
        std::cout << i << ' ';
    std::cout << '\n';

    v.resize(5); // grow back to 5 elements
    printCapLen(v);

    for (auto i : v)
        std::cout << i << ' ';
    std::cout << '\n';

    return 0;
}
