// ============================================================
// 来源小节：17.9 Pointer arithmetic and subscripting
// 示例说明：对指针做下标——ptr[n] 等价于 *((ptr) + (n))（原 Example 4）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointer-arithmetic-and-subscripting/
// 预期输出：5
// ============================================================
#include <iostream>

int main()
{
    const int arr[]{ 9, 7, 5, 3, 1 }; // our array has elements of type int
    const int* ptr{ arr };            // arr decays into a pointer

    std::cout << ptr[2]; // subscript ptr to get element 2, prints 5

    return 0;
}
