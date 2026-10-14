// ============================================================
// 来源小节：16.10 std::vector resizing and capacity
// 示例说明：resize(0) 只把长度降为 0、并不释放已分配的存储；
//           随后 shrink_to_fit() 才请求把容量缩减到与长度相同（本例释放了全部存储）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdvector-resizing-and-capacity/
// 预期输出（原作者机器上的结果，可能因实现而异）：
//   Capacity: 1000  Length: 1000
//   Capacity: 1000  Length: 0
//   Capacity: 0  Length: 0
// 备注：本节代码为按原文描述重建。shrink_to_fit() 是非强制请求，
//       某些实现可能只部分缩减或干脆忽略。
// ============================================================
#include <iostream>
#include <vector>

void printCapLen(const std::vector<int>& v)
{
    std::cout << "Capacity: " << v.capacity() << "  Length: " << v.size() << '\n';
}

int main()
{
    std::vector<int> v(1000); // allocate room for 1000 elements
    printCapLen(v);

    v.resize(0); // resize to 0 elements
    printCapLen(v);

    v.shrink_to_fit(); // shrink the capacity to fit the length
    printCapLen(v);

    return 0;
}
