// ============================================================
// 来源小节：17.8 C-style array decay
// 示例说明：用数组语法 const int arr[] 作为形参，行为与 const int* 完全相同（原 Example 8）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/c-style-array-decay/
// 预期输出：
//   2
//   1
// ============================================================
#include <iostream>

void printElementZero(const int arr[]) // treated the same as const int*
{
    std::cout << arr[0];
}

int main()
{
    const int prime[] { 2, 3, 5, 7, 11 };
    const int squares[] { 1, 4, 9, 25, 36, 49, 64, 81 };

    printElementZero(prime);   // prime decays to a pointer
    printElementZero(squares); // squares decays to a pointer

    return 0;
}
