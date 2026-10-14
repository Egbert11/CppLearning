// ============================================================
// 来源小节：17.12 Multidimensional C-style Arrays
// 示例说明：多维 C 风格数组的声明片段——1d、2d（数组的数组）、3d，以及双下标访问
//           （原文 Example 1~6 的声明片段）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/multidimensional-c-style-arrays/
// 预期输出：7（随后一行打印各数组元素 0）
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

int main()
{
    // 1d 数组：井字棋棋盘（0 = 空, 1 = 玩家1, 2 = 玩家2）
    int ttt[9]{}; // a C-style array of ints (value 0 = empty, 1 = player 1, 2 = player 2)
    // ttt[0] ttt[1] ttt[2] ttt[3] ttt[4] ttt[5] ttt[6] ttt[7] ttt[8]

    // 2d 数组：元素类型本身是数组
    int a[3][5]; // a 3-element array of 5-element arrays of int

    // 用两个下标访问：a[row][col]
    a[2][3] = 7; // a[row][col], where row = 2 and col = 3

    // 井字棋写成 2d 数组
    int ttt2[3][3]{};

    // 三维数组
    int threedee[4][4][4]{}; // a 4x4x4 array (an array of 4 arrays of 4 arrays of 4 ints)

    std::cout << a[2][3] << '\n'; // 7
    std::cout << ttt[0] << ' ' << ttt2[0][0] << ' ' << threedee[0][0][0] << '\n'; // 0 0 0

    return 0;
}
