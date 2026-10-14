// ============================================================
// 来源小节：19.1 Dynamic memory allocation with new and delete
// 示例说明：两个指针指向同一块动态内存；delete 一个并置空，另一个仍然悬垂。
// 原文链接：https://www.learncpp.com/cpp-tutorial/dynamic-memory-allocation-with-new-and-delete/
// 预期输出：无（本程序不会解引用 otherPtr，所以运行时不触发未定义行为）
// 备注：坏实践示例（-broken）：otherPtr 是被遗忘的悬垂指针，任何后续解引用
//       或 delete 都是未定义行为。演示"避免多个指针指向同一块动态内存"的规范。
// ============================================================
#include <iostream>

int main()
{
    int* ptr{ new int{} }; // dynamically allocate an integer
    int* otherPtr{ ptr }; // otherPtr is now pointed at that same memory location

    delete ptr; // return the memory to the operating system.  ptr and otherPtr are now dangling pointers.
    ptr = nullptr; // ptr is now a nullptr

    // however, otherPtr is still a dangling pointer!

    (void)otherPtr; // 原文无此行；仅为避免"未使用变量"警告

    return 0;
}
