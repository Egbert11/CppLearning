// ============================================================
// 来源小节：17.8 C-style array decay
// 示例说明：一个函数同时接受两种不同长度的数组（参数写成 const int*）（原 Example 7）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/c-style-array-decay/
// 预期输出：
//   2
//   1
// ============================================================
#include <iostream>

void printElementZero(const int* arr) // pass by const address
{
    std::cout << arr[0];
}

int main()
{
    const int prime[] { 2, 3, 5, 7, 11 };
    const int squares[] { 1, 4, 9, 25, 36, 49, 64, 81 };

    printElementZero(prime);   // prime decays to an const int* pointer
    printElementZero(squares); // squares decays to an const int* pointer

    return 0;
}
