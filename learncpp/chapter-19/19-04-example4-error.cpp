// ============================================================
// 来源小节：19.4 Pointers to pointers and dynamic multidimensional arrays
// 示例说明：定长二维数组 int[10][5] 很好写，但直接 new int[10][5] 不成立——
//           二维动态数组需要下面几种技巧之一。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointers-to-pointers/
// 预期错误：编译失败。new int[10][5] 本身合法，但它的类型是 int(*)[5]
//           （指向"含 5 个 int 的数组"的指针），无法用来初始化 int**，
//           故报 "cannot convert 'int (*)[5]' to 'int**' in initialization"。
// 备注：预期编译失败（-error），请勿修复。原文 Example 7/8。
// ============================================================
#include <iostream>

int main()
{
    int array[10][5]; // 定长二维数组：合法
    (void)array;

    int** array2 { new int[10][5] }; // won't work!

    std::cout << array2[0][0] << '\n';

    return 0;
}
