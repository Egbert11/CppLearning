// 来源小节：20.2 The stack and the heap
// 示例说明：new 在堆（heap，又称 free store）上分配内存，
//           并演示动态内存需要手动 delete 归还。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-stack-and-the-heap/
// 说明：本节代码为按原文描述重建。
// 说明：连续两次 new 得到的地址不保证是连续的。

#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int* ptr { new int };      // new int allocates 4 bytes in the heap
    int* array { new int[10] }; // new int[10] allocates 40 bytes in the heap
    // --- 原文示例片段结束 ---

    *ptr = 42;
    array[0] = 1;

    std::cout << "ptr  = " << ptr << '\n';
    std::cout << "array = " << static_cast<void*>(array) << '\n';

    // --- 原文示例片段 ---
    int* ptr1 { new int };
    int* ptr2 { new int };
    // ptr1 and ptr2 may not have sequential addresses
    // --- 原文示例片段结束 ---

    std::cout << "ptr1 = " << ptr1 << '\n';
    std::cout << "ptr2 = " << ptr2 << '\n';

    // Deleting a pointer returns the memory at that address to the heap;
    // it does not delete the variable itself.
    delete ptr;
    delete[] array;
    delete ptr1;
    delete ptr2;

    return 0;
}
