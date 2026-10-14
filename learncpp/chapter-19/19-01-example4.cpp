// ============================================================
// 来源小节：19.1 Dynamic memory allocation with new and delete
// 示例说明：动态分配一个 int、通过指针写入并解引用读取，最后 delete 并置空。
// 原文链接：https://www.learncpp.com/cpp-tutorial/dynamic-memory-allocation-with-new-and-delete/
// 预期输出：7
// 备注：本节代码为按原文描述重建（对应原文 Example 4/5/7 的合并演示）。
// ============================================================
#include <iostream>

int main()
{
    int* ptr{ new int }; // dynamically allocate an integer and assign the address to ptr so we can access it later

    *ptr = 7; // assign value of 7 to allocated memory

    std::cout << *ptr << '\n'; // dereference ptr to read the value back

    // assume ptr has previously been allocated with operator new
    delete ptr; // return the memory pointed to by ptr to the operating system
    ptr = nullptr; // set ptr to be a null pointer

    return 0;
}
