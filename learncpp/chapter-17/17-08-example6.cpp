// ============================================================
// 来源小节：17.8 C-style array decay
// 示例说明：对保存数组首地址的指针做下标访问（原 Example 6）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/c-style-array-decay/
// 预期输出：5
// ============================================================
#include <iostream>

int main()
{
    const int arr[] { 9, 7, 5, 3, 1 };

    const int* ptr{ arr };  // arr decays into a pointer
    std::cout << ptr[2];    // subscript ptr to get element 2, prints 5

    return 0;
}
