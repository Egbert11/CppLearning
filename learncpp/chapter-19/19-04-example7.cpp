// ============================================================
// 来源小节：19.4 Pointers to pointers and dynamic multidimensional arrays
// 示例说明：最右侧维度不是编译期常量时，先分配指针数组（行），再循环为每个元素
//           分配一维动态数组（列）——即"动态一维数组的动态一维数组"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointers-to-pointers/
// 预期输出：3
// 备注：本节代码为按原文描述重建（原文 Example 11/12/14）。
//       释放必须"先删各列、最后删外层数组"，且与分配顺序相反，避免访问已释放内存。
// ============================================================
#include <iostream>

int main()
{
    int** array { new int*[10] }; // allocate an array of 10 int pointers — these are our rows
    for (int count { 0 }; count < 10; ++count)
        array[count] = new int[5]; // these are our columns

    array[9][4] = 3; // This is the same as (array[9])[4] = 3;

    std::cout << array[9][4] << '\n';

    // 释放：先把每一列删掉，最后删外层数组（顺序与分配相反）
    for (int count { 0 }; count < 10; ++count)
        delete[] array[count];
    delete[] array; // this needs to be done last

    return 0;
}
