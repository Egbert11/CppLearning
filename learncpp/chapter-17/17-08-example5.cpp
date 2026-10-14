// ============================================================
// 来源小节：17.8 C-style array decay
// 示例说明：对退化为指针的数组直接下标访问（原 Example 5）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/c-style-array-decay/
// 预期输出：5
// ============================================================
#include <iostream>

int main()
{
    const int arr[] { 9, 7, 5, 3, 1 };
    std::cout << arr[2]; // subscript decayed array to get element 2, prints 5

    return 0;
}
