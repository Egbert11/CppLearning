// ============================================================
// 来源小节：19.1 Dynamic memory allocation with new and delete
// 示例说明：把持有动态地址的指针重新赋值，旧地址丢失——内存泄漏。
// 原文链接：https://www.learncpp.com/cpp-tutorial/dynamic-memory-allocation-with-new-and-delete/
// 预期输出：5
// 备注：坏实践示例（-broken），可编译。原文 Example 15。
// ============================================================
#include <iostream>

int main()
{
    int value = 5;
    int* ptr{ new int{} }; // allocate memory
    ptr = &value; // old address lost, memory leak results

    std::cout << *ptr << '\n';

    // 原动态内存的地址已丢失，无法再释放。

    return 0;
}
