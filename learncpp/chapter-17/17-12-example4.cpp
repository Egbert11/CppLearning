// ============================================================
// 来源小节：17.12 Multidimensional C-style Arrays
// 示例说明：省略最左边维度（编译器根据初始化器数量推导），以及全零初始化（原 Example 10、12）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/multidimensional-c-style-arrays/
// 预期输出：
//   15
//   0
// ============================================================
#include <iostream>

int main()
{
    // 省略最左边的长度：编译器数初始化器来推导
    int array[][5]
    {
        { 1, 2, 3, 4, 5 },     // row 0
        { 6, 7, 8, 9, 10 },    // row 1
        { 11, 12, 13, 14, 15 } // row 2
    };

    // 用空花括号把多维数组全部零初始化
    int zero[3][5] {};

    std::cout << array[2][4] << '\n'; // 15
    std::cout << zero[1][2] << '\n';  // 0

    return 0;
}
