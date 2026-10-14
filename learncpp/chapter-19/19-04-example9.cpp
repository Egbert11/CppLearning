// ============================================================
// 来源小节：19.4 Pointers to pointers and dynamic multidimensional arrays
// 示例说明：把 x×y 的二维数组"拍平"为一维数组，配合下标换算函数访问，
//           避免成对分配/释放易出错的问题。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointers-to-pointers/
// 预期输出：3
// 备注：本节代码为按原文描述重建（原文 Example 15/16）。
// ============================================================
#include <iostream>

int getSingleIndex(int row, int col, int numberOfColumnsInArray)
{
    return (row * numberOfColumnsInArray) + col;
}

int main()
{
    constexpr int rows { 10 };
    constexpr int cols { 5 };

    int* array { new int[rows * cols]{} }; // a 10x5 array flattened into a single array

    array[getSingleIndex(9, 4, cols)] = 3; // 访问 (9, 4)

    std::cout << array[getSingleIndex(9, 4, cols)] << '\n';

    delete[] array;

    return 0;
}
