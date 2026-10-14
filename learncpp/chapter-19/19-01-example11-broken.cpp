// ============================================================
// 来源小节：19.1 Dynamic memory allocation with new and delete
// 示例说明：指针本身是局部变量，函数返回时被销毁，它指向的堆内存再无人释放——内存泄漏。
// 原文链接：https://www.learncpp.com/cpp-tutorial/dynamic-memory-allocation-with-new-and-delete/
// 预期输出：Memory leaked
// 备注：坏实践示例（-broken），可编译。演示"动态内存的生存期不随指针作用域自动结束"。
// ============================================================
#include <iostream>

void doSomething()
{
    int* ptr{ new int{} }; // 动态分配
    *ptr = 7;

    // 函数返回时 ptr 被销毁，但它指向的堆内存从未被 delete —— 内存泄漏。
}

int main()
{
    doSomething();

    std::cout << "Memory leaked\n";

    return 0;
}
