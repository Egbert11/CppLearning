// ============================================================
// 来源小节：16.10 std::vector resizing and capacity
// 示例说明：同时打印 capacity 与 length，观察把 3 个元素的 vector 调大到 5 时，
//           由于超过原容量 3，vector 必须获取更多存储，容量随之提高到 5。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdvector-resizing-and-capacity/
// 预期输出（原作者机器上的结果，可能因实现而异）：
//   Capacity: 3  Length: 3
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
    std::vector v { 0, 1, 2 }; // length is initially 3
    printCapLen(v);

    for (auto i : v)
        std::cout << i << ' ';
    std::cout << '\n';

    v.resize(5); // resize to 5 elements

    printCapLen(v);

    for (auto i : v)
        std::cout << i << ' ';
    std::cout << '\n';

    return 0;
}
