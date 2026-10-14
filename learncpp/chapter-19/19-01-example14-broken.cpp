// ============================================================
// 来源小节：19.1 Dynamic memory allocation with new and delete
// 示例说明：对同一指针连续两次 new，第一次分配的地址丢失——内存泄漏。
// 原文链接：https://www.learncpp.com/cpp-tutorial/dynamic-memory-allocation-with-new-and-delete/
// 预期输出：7
// 备注：坏实践示例（-broken），可编译。原文 Example 17。
// ============================================================
#include <iostream>

int main()
{
    int* ptr{ new int{} };
    ptr = new int{}; // old address lost, memory leak results

    *ptr = 7;
    std::cout << *ptr << '\n';

    delete ptr; // 只释放了第二次分配的内存

    return 0;
}
