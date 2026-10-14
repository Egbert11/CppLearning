// ============================================================
// 来源小节：17.13 Multidimensional std::array
// 示例说明：规范的二维 std::array（注意双花括号）与下标访问（原 Example 1~2）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/multidimensional-stdarray/
// 预期输出：7
// ============================================================
#include <array>
#include <iostream>

int main()
{
    // C-style 2d array（作为对照）
    // int arr[3][4] {
    //     { 1, 2, 3, 4 },
    //     { 5, 6, 7, 8 },
    //     { 9, 10, 11, 12 }};

    std::array<std::array<int, 4>, 3> arr {{  // note double braces
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 }}};

    std::cout << arr[1][2]; // print the element in row 1, column 2

    return 0;
}
