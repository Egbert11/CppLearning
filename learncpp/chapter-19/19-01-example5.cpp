// ============================================================
// 来源小节：19.1 Dynamic memory allocation with new and delete
// 示例说明：动态分配单个变量时用直接初始化与统一初始化两种写法赋初值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/dynamic-memory-allocation-with-new-and-delete/
// 预期输出：5 6
// 备注：本节代码为按原文描述重建（原文 Example 6）。
// ============================================================
#include <iostream>

int main()
{
    int* ptr1{ new int (5) }; // use direct initialization
    int* ptr2{ new int { 6 } }; // use uniform initialization

    std::cout << *ptr1 << ' ' << *ptr2 << '\n';

    delete ptr1;
    delete ptr2;

    return 0;
}
