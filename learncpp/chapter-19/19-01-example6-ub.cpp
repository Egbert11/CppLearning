// ============================================================
// 来源小节：19.1 Dynamic memory allocation with new and delete
// 示例说明：解引用悬垂指针，并对同一块内存重复 delete——两者都是未定义行为。
// 原文链接：https://www.learncpp.com/cpp-tutorial/dynamic-memory-allocation-with-new-and-delete/
// 预期输出：未定义。可能打印垃圾值、可能崩溃（例如 glibc 报 double free），
//           也可能"看似正常"。若进程在缓冲刷新前终止，可能看不到任何输出。
// 备注：未定义行为演示（-ub），能编译；请勿把其输出当作可依赖结果。
// ============================================================
#include <iostream>

int main()
{
    int* ptr{ new int }; // dynamically allocate an integer
    *ptr = 7; // put a value in that memory location

    delete ptr; // return the memory to the operating system.  ptr is now a dangling pointer.

    std::cout << *ptr; // Dereferencing a dangling pointer will cause undefined behavior
    delete ptr; // trying to deallocate the memory again will also lead to undefined behavior.

    return 0;
}
