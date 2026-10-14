// ============================================================
// 来源小节：19.1 Dynamic memory allocation with new and delete
// 示例说明：分配一个 int 却丢弃 new 返回的指针——内存泄漏（再也无法释放这块内存）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/dynamic-memory-allocation-with-new-and-delete/
// 预期输出：Allocated but lost the address
// 备注：坏实践示例（-broken）。可编译；泄漏的内存只能等程序结束时由操作系统回收。
// ============================================================
#include <iostream>

int main()
{
    new int; // dynamically allocate an integer (and discard the result)

    std::cout << "Allocated but lost the address\n";

    return 0;
}
