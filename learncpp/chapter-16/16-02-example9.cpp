// ============================================================
// 来源小节：16.2 Introduction to std::vector and list constructors
// 示例说明：const vector 的元素不可修改，只能读取。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdvector-and-list-constructors/
// 预期输出：2
// 备注：本节代码为按原文描述重建。取消注释 prime[0] = 1; 会导致编译失败。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    const std::vector<int> prime { 2, 3, 5, 7, 11 }; // elements cannot be modified

    std::cout << prime[0] << '\n'; // ok: reading is allowed

    // prime[0] = 1; // compile error: cannot assign to element of a const vector

    return 0;
}
