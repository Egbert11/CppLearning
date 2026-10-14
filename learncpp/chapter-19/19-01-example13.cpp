// ============================================================
// 来源小节：19.1 Dynamic memory allocation with new and delete
// 示例说明：重新赋值指针前先 delete 原来的动态内存，避免泄漏。
// 原文链接：https://www.learncpp.com/cpp-tutorial/dynamic-memory-allocation-with-new-and-delete/
// 预期输出：5
// 备注：本节代码为按原文描述重建（原文 Example 16）。
// ============================================================
#include <iostream>

int main()
{
    int value{ 5 };
    int* ptr{ new int{} }; // allocate memory
    delete ptr; // return memory back to operating system
    ptr = &value; // reassign pointer to address of value

    std::cout << *ptr << '\n';

    return 0;
}
