// ============================================================
// 来源小节：19.1 Dynamic memory allocation with new and delete
// 示例说明：仅当指针为空（尚未分配）时才分配内存——条件式分配。
// 原文链接：https://www.learncpp.com/cpp-tutorial/dynamic-memory-allocation-with-new-and-delete/
// 预期输出：5
// 备注：本节代码为按原文描述重建（原文 Example 12）。
// ============================================================
#include <iostream>

int main()
{
    int* ptr{ nullptr };

    // If ptr isn't already allocated, allocate it
    if (!ptr)
        ptr = new int{ 5 };

    std::cout << *ptr << '\n';

    delete ptr;

    return 0;
}
