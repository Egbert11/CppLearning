// ============================================================
// 来源小节：16.2 Introduction to std::vector and list constructors
// 示例说明：值初始化的 std::vector<int> 开始时含 0 个元素。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdvector-and-list-constructors/
// 预期输出：empty: 0
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> empty{}; // vector containing 0 int elements

    std::cout << "empty: " << empty.size() << '\n';

    return 0;
}
